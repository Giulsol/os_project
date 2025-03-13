#ifndef ACCELERATOR_TEST_H
#define ACCELERATOR_TEST_H

#define DEVICE_NAME "accelerator"
#define ACC_BASE_ADDR 0x090c0000


#define REG_START 0x0
#define REG_WORKING 0x8
#define REG_FINISHED 0x10
#define REG_N_IN_CHANNELS 0x18

#define REG_COEFFICIENTS 0x20 //from 0x20 to 0x60: 64 bytes for 8 sets of filters

#define REG_DATAIN 0x60 //from 0x60 to 0x260: 32 bytes for each channel * 16 = 512 bytes

#define REG_DATAOUT 0x260 //from 0x260 to 0x460: 64 bytes for each channel * 8 = 512 bytes

#define SEQ_LENGTH 0x4960 //how many words_packages (1 package = 64 bits = 8 words) for each channel

#define ACC_REG_SIZE 0x5000

struct inputstruct {
    int64_t n_input_channels;
    int64_t sequence_length;
    int64_t coefficients[8];
    int64_t data_in_struct[16][4];
    int64_t data_out_struct[8][25];
};

#define ACCELERATOR_FUNC _IOWR('a', 'b', struct inputstruct *)

#endif
