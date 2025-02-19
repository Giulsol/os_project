#ifndef HW_ACCELERATOR_H
#define HW_ACCELERATOR_H

#include "hw/arm/virt.h"
#include "qom/object.h"

DeviceState *accelerator_create(const VirtMachineState *vms, int accelerator);

#endif // HW_ACCELERATOR_H