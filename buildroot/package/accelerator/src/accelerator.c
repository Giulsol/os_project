#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Giulia Solito, Martina di Leo, Alice Afragoli");
MODULE_DESCRIPTION("A simple hello world module");
MODULE_VERSION("0.01");

static int __init accel_init(void)
{
        pr_info("Hello world from kernel!! \n");
        return 0;
}

static void __exit accel_exit(void)
{
        pr_info("Exiting hello world module from kernel !!!\n");
}

module_init(accel_init);
module_exit(accel_exit);

