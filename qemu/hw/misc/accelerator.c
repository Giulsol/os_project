#include "qemu/osdep.h"
#include "qemu/log.h"
#include "qapi/error.h"
#include "hw/sysbus.h"
#include "qemu/typedefs.h"
#include "hw/irq.h"
#include "hw/misc/accelerator.h"
#include "accel/accel.h"
#include "hw/arm/fdt.h" 
#include "sysemu/device_tree.h"

#include <stdint.h>

#define TYPE_ACCELERATOR "accelerator"

#define max_in_channels 16
#define kernel_size 8
#define max_in_wordspackage_per_channel 4  
#define max_bytes_per_channel_in 32
#define output_word_bytes 8
#define in_words_per_transaction 8

#define REG_START 0x0
#define REG_WORKING 0x8
#define REG_FINISHED 0x10
#define REG_N_IN_CHANNELS 0x18

#define REG_COEFFICIENTS 0x20 //from 0x20 to 0x60: 64 bytes for 8 sets of filters

#define REG_DATAIN 0x60 //from 0x60 to 0x260: 32 bytes for each channel * 16 = 512 bytes

#define REG_DATAOUT 0x260 //from 0x260 to 0x460: 64 bytes for each channel * 8 = 512 bytes

#define SEQ_LENGTH 0x4960 //how many words_packages (1 package = 64 bits = 8 words) for each channel

#define ACCELERATOR_REG_SIZE 0x5000 

#define CHIP_ID 0xBA000001

typedef struct accelerator_state AcceleratorState;
DECLARE_INSTANCE_CHECKER(AcceleratorState, ACCELERATOR_DEVICE, TYPE_ACCELERATOR);

//the application gives the number of input channels, that can be 16 at maximum

struct accelerator_state {
    SysBusDevice parent;
    MemoryRegion iomem;

    uint64_t chip_id;
    uint64_t start;
    uint64_t working;
    uint64_t finished;
    uint64_t n_in_channels;
    uint64_t coefficients[in_words_per_transaction];
    uint64_t input_data[max_in_channels][max_in_wordspackage_per_channel];
    uint64_t output_data[kernel_size][max_in_wordspackage_per_channel*output_word_bytes+1];
    uint64_t sequence_length;

};

static uint64_t accelerator_read(void *opaque, hwaddr addr, unsigned int size) {
    uint64_t reading_offset, row, column;
    AcceleratorState *state = (AcceleratorState*)opaque;

    if (addr == REG_START) {
        return state->start;
    }
    else if (addr == REG_WORKING) {
        return state->working;
    }
    else if (addr == REG_FINISHED) {
        return state->finished;
    }
    else if (addr == REG_N_IN_CHANNELS) {
        return state->n_in_channels;
    }
    else if ((addr >= REG_COEFFICIENTS) && (addr < REG_DATAIN)) {
        reading_offset = (addr - REG_COEFFICIENTS);
        return state->coefficients[reading_offset/output_word_bytes];
    }
    else if ((addr >= REG_DATAIN) && (addr < REG_DATAOUT)) {
        reading_offset = (addr - REG_DATAIN);
        row = reading_offset / max_bytes_per_channel_in;
        column = (reading_offset % max_bytes_per_channel_in) / (in_words_per_transaction);
        return state->input_data[row][column];
    }
    else if ((addr >= REG_DATAOUT) && (addr < SEQ_LENGTH)) {
        reading_offset = (addr - REG_DATAOUT);
        row = reading_offset / ((max_in_wordspackage_per_channel*output_word_bytes+1)*in_words_per_transaction);
        column = reading_offset % ((max_in_wordspackage_per_channel*output_word_bytes+1)*in_words_per_transaction) / (output_word_bytes);
        return state->output_data[row][column];
    }
    else if (addr == SEQ_LENGTH) {
        return state->sequence_length;
    }
    else {
        qemu_log_mask(LOG_GUEST_ERROR, "Reading not allowed at this address\n");
    }

    return 0;
}

static void accelerator_write(void *opaque, hwaddr addr, uint64_t value, unsigned int size) {
    uint64_t offset;
    AcceleratorState *state = (AcceleratorState*)opaque;

    if (addr == REG_START) {
        state->start = value;
        if (state->n_in_channels == 0) {
            state->start = 0;
            qemu_log_mask(LOG_GUEST_ERROR, "The number of input channels is missing\n");
        }
        else if (state->sequence_length == 0) {
            state->start = 0;
            qemu_log_mask(LOG_GUEST_ERROR, "The number of package words for input channels is missing\n");
        }
        else {
            for (int i=0; i<8; i++) {
                if (state->coefficients[i] == 0) {
                    state->start = 0;
                    qemu_log_mask(LOG_GUEST_ERROR, "Coefficients of filter %d are the standard ones\n", i+1);
                }
            }
            for (int i=0; i<state->n_in_channels; i++) {
                for (int j=0; j<state->sequence_length; j++) {
                    if (state->input_data[i][j] == 0) {
                        state->start = 0;
                        qemu_log_mask(LOG_GUEST_ERROR, "Data from channel %d is missing\n", i+1);
                    }
                }
            }
        }
        if (state->start == 1) {
            state->working = 1;
            uint64_t sum[(max_in_wordspackage_per_channel-1)*in_words_per_transaction+1];
            for (int j=0; j<kernel_size; j++) {
                convolution_8_per_n_ch_in(state->input_data, state->coefficients[j], state->n_in_channels, state->sequence_length, sum);
                for (int k=0; k<(state->sequence_length)*output_word_bytes+1; k++) {
                    state->output_data[j][k] = sum[k];
                }
            }
            state->working = 0;
            state->finished = 1;
        }
    }
    else if (addr == REG_FINISHED) {
        state->finished = value;
        state->start = 0;
    }
    else if (addr == REG_N_IN_CHANNELS) {
        state->n_in_channels = value;
        if (state->n_in_channels > max_in_channels || state->n_in_channels == 0) {
            state->n_in_channels = 0;
            qemu_log_mask(LOG_GUEST_ERROR, "The number of input channels is not valid:\n it must be a number between 1 and 16\n");
        }
    }
    else if ((REG_COEFFICIENTS <= addr) && (addr < REG_DATAIN)) {
        offset = addr - REG_COEFFICIENTS;
        state->coefficients[offset/8] = value;
    }
    else if ((REG_DATAIN <= addr) && (addr < REG_DATAOUT)) {
        offset = addr - REG_DATAIN;
        if (offset < max_bytes_per_channel_in) {
            state->input_data[0][offset/8] = value;
        }
        else if (offset < 2*max_bytes_per_channel_in) {
            state->input_data[1][(offset-max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 3*max_bytes_per_channel_in) {
            state->input_data[2][(offset-2*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 4*max_bytes_per_channel_in) {
            state->input_data[3][(offset-3*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 5*max_bytes_per_channel_in) {
            state->input_data[4][(offset-4*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 6*max_bytes_per_channel_in) {
            state->input_data[5][(offset-5*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 7*max_bytes_per_channel_in) {
            state->input_data[6][(offset-6*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 8*max_bytes_per_channel_in) {
            state->input_data[7][(offset-7*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 9*max_bytes_per_channel_in) {
            state->input_data[8][(offset-8*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 10*max_bytes_per_channel_in) {
            state->input_data[9][(offset-9*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 11*max_bytes_per_channel_in) {
            state->input_data[10][(offset-10*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 12*max_bytes_per_channel_in) {
            state->input_data[11][(offset-11*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 13*max_bytes_per_channel_in) {
            state->input_data[12][(offset-12*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 14*max_bytes_per_channel_in) {
            state->input_data[13][(offset-13*max_bytes_per_channel_in)/8] = value;
        }
        else if (offset < 15*max_bytes_per_channel_in) {
            state->input_data[14][(offset-14*max_bytes_per_channel_in)/8] = value;
        }
        else {
            state->input_data[15][(offset-15*max_bytes_per_channel_in)/8] = value;
        }
    }
    else if (addr == SEQ_LENGTH) {
        state->sequence_length = value;
        if (state->sequence_length > max_in_wordspackage_per_channel || state->sequence_length == 0) {
            state->sequence_length = 0;
            qemu_log_mask(LOG_GUEST_ERROR, "The length of input package words is not valid:\n it must be a number between 1 and 4\n");
        }
    }
    else {
        qemu_log_mask(LOG_GUEST_ERROR, "Writing not allowed at this address\n");
    }
}

static const MemoryRegionOps accelerator_ops = {
    .read = accelerator_read,
    .write = accelerator_write,
    .endianness = DEVICE_LITTLE_ENDIAN,

    .impl = {
        .min_access_size = 4,
        .max_access_size = 8,
    },
    .valid = {
        .min_access_size = 4,
        .max_access_size = 8,
    }
};

static void accelerator_instance_init(Object *obj) {
    AcceleratorState *state = ACCELERATOR_DEVICE(obj);

    memory_region_init_io(&state->iomem, obj, &accelerator_ops,state, TYPE_ACCELERATOR, ACCELERATOR_REG_SIZE);
    sysbus_init_mmio(SYS_BUS_DEVICE(obj), &state->iomem);
    state->chip_id = CHIP_ID;
    state->start = 0xAB0;
    state->working = 0xC00;
    state->finished = 0xFF00;
    state->n_in_channels = 0x004;

    state->coefficients[0] = 0x12345678;
    state->coefficients[1] = 0x1AB77D93;
    state->coefficients[2] = 0xDEADBEEF;
    state->coefficients[3] = 0x569387FF;
    state->coefficients[4] = 0xAAAABBBB;
    state->coefficients[5] = 0x99374481;
    state->coefficients[6] = 0xB1135C65;
    state->coefficients[7] = 0x66968EED;

    for (int i=0; i<max_in_channels; i++) {
        for (int j=0; j<max_in_wordspackage_per_channel; j++) {
            state->input_data[i][j] = 0;
        }
    }
    for (int i=0; i<kernel_size; i++) {
        for (int j=0; j<max_in_wordspackage_per_channel*output_word_bytes+1; j++) {
            state->output_data[i][j] = 0;
        }
    }
    state->sequence_length = 0x3;
}

static const TypeInfo accelerator_info = {
    .name = TYPE_ACCELERATOR,
    .parent = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(AcceleratorState),
    .instance_init = accelerator_instance_init
};

static void accelerator_register_types(void) {
    type_register_static(&accelerator_info);
};

type_init(accelerator_register_types);


DeviceState *accelerator_create(const VirtMachineState *vms, int accelerator) {
    DeviceState *dev = qdev_new(TYPE_ACCELERATOR);
    MachineState *ms = MACHINE(vms);
    hwaddr base = vms->memmap[accelerator].base;
    hwaddr size = vms->memmap[accelerator].size;
    assert(size == ACCELERATOR_REG_SIZE);
    sysbus_realize_and_unref(SYS_BUS_DEVICE(dev), &error_fatal);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, base);
    return dev;
}

