#include <linux/init.h> // Needed for the macros
#include <linux/module.h> // Needed by all modules
#include <linux/kernel.h> 
#include <linux/fs.h> // File operation structure
#include <linux/cdev.h> // Char driver
#include <asm/uaccess.h> // copy_to_user and copy_from_user
#include <linux/io.h>
#include <linux/device.h>
#include "accelerator_test.h"

MODULE_AUTHOR("group7");
MODULE_DESCRIPTION("Kernel module for accelerator");
MODULE_LICENSE("GPL");

static int major_num;
static struct class *cls;
static void __iomem *acc_base;


static long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param) {
	struct inputstruct input_data;

	//pass the ioctl_param from user space to kernel space (input_data)
	if (copy_from_user(&input_data, (struct inputstruct *)ioctl_param, sizeof(input_data)) != 0) {
        return -1;
	}

	if (ioctl_num == ACCELERATOR_FUNC) {
		//write number of input channels into the register
		iowrite64(input_data.n_input_channels, acc_base + REG_N_IN_CHANNELS);
		
		//write sequence length 
		iowrite64(input_data.sequence_length, acc_base + SEQ_LENGTH);
		
		//write filter coefficients (8 sets of 8 coefficients, each coeff of 8 bits)
		for (int i = 0; i < 8; i++) {
			iowrite64(input_data.coefficients[i], acc_base + REG_COEFFICIENTS + (i*8));
		}
		
		//write input data (depends on the number of input channels), each input word is 8 bits 
		for (int k = 0; k < input_data.n_input_channels; k++) {
			for (int j = 0; j < MAX_SEQ_LENGTH; j++) {
				//only fill the actual needed input data with the given values
				if (j < input_data.sequence_length) {
					iowrite64(input_data.data_in_struct[k][j], acc_base + REG_DATAIN + (j*8) + (k*8*MAX_SEQ_LENGTH));
				}
				//all other words are filled with 0
				else {
					iowrite64(0, acc_base + REG_DATAIN + (j*8) + (k*8*MAX_SEQ_LENGTH));
				}
			}
		}
		
		//the hw can start its computation
		iowrite64(0x1, acc_base + REG_START);
		
		while (ioread64(acc_base + REG_FINISHED) != 1) {
			//wait until it is done computing 
		}
		
		//the finished bit is lowered by the driver and this will automatically lower also the start bit
		iowrite64(0x0, acc_base + REG_FINISHED);
		
		//copying output data from registers to the data struct
		//we always have 8 output channels
		for (int m = 0; m < 8; m++) {
			for (int n = 0; n < MAX_SEQ_LENGTH*8+1; n++) {
				if (n < (input_data.sequence_length*8)-8+1) {
					input_data.data_out_struct[m][n] = ioread64(acc_base + REG_DATAOUT + (n*8) + (m*8*(MAX_SEQ_LENGTH*8+1)));
				}
				else {
					input_data.data_out_struct[m][n] = 0;
				}
			}
		}

		if (copy_to_user((struct inputstruct *)ioctl_param, &input_data, sizeof(input_data)) != 0) {
			return -1;
		}
	}
	else {
		return -1;
	} 

	return 0;
}

// Module declarations

// structure that holds the functions that allow to perform operations on the device
static struct file_operations accel_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = device_ioctl
};

// initialization of the character device
static int __init accel_init(void)
{
	//register device and get major number
	major_num = register_chrdev(0, DEVICE_NAME, &accel_fops);
	if (major_num < 0) {
		pr_alert("Registering char device failed with %d\n", major_num);
		return major_num;
	}
	pr_info("Assigned major number: %d\n", major_num);
	
	cls = class_create(DEVICE_NAME);
	if (cls == NULL) {
		unregister_chrdev(major_num, DEVICE_NAME);
		pr_err(KERN_ALERT "ACC: Failed to class create\n");
		return -1;
	}
	
	if (device_create(cls, NULL, MKDEV(major_num, 0), NULL, DEVICE_NAME) == NULL) {
		class_destroy(cls);
		unregister_chrdev(major_num, DEVICE_NAME);
		pr_err(KERN_ALERT "ACC: Failed to create device\n");
		return -1;
	}
	pr_info("Device created on /dev/%s\n", DEVICE_NAME);

	acc_base = ioremap(ACC_BASE_ADDR, ACC_REG_SIZE);
    	if (!acc_base) {
		device_destroy(cls, MKDEV(major_num, 0));
		class_destroy(cls);
		unregister_chrdev(major_num, DEVICE_NAME);
		pr_err(KERN_ALERT "ACC: Failed to map memory\n");
		return -1;
	}
	return 0;
}

//unregister the device
static void __exit accel_exit(void)
{
	iounmap(acc_base);
	device_destroy(cls, MKDEV(major_num, 0));
	class_destroy(cls);
	unregister_chrdev(major_num, DEVICE_NAME);
	pr_info("Module removed\n");
}

module_init(accel_init);
module_exit(accel_exit);
