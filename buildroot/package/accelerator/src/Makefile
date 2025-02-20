obj-m += accelerator.o

KERNEL_SOURCES ?= ../../../output/build/linux-6.12.9


all:
	make -C $(KERNEL_SOURCES) M=$(PWD) modules

clean:
	rm -rf ./cache *.cmd *.ko *.order *.o *.mod *.mod.c *.symvers

