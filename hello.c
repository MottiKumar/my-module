#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A modified Hello World kernel module that triggers a kernel panic");
MODULE_LICENSE("GPL");


static char *message = "default message";
module_param(message, charp, 0000);
MODULE_PARM_DESC(message, "A string parameter for the Hello World module");

#define OP_READ         0
#define OP_WRITE        1
#define OP_OOPS         OP_WRITE

static int __init custom_init(void) {
    int *a;

    printk(KERN_ALERT "Kernel panic triggered by hello module\n");

    // Intentionally cause a kernel oops by writing to a bad memory address
    a = (int *)0x00001234;
#if OP_OOPS == OP_WRITE
    *a = 3;
#elif OP_OOPS == OP_READ
    printk(KERN_ALERT "value = %d\n", *a);
#else
#error "Unknown op for oops!"
#endif

    panic("Intentional panic from Hello World kernel module. Parameter message: %s", message);
    return 0;
}

static void __exit custom_exit(void) {
    printk(KERN_INFO "Exiting Hello World module\n");
}

module_init(custom_init);
module_exit(custom_exit);
