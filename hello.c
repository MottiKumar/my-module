#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

static char *message = "default message";
module_param(message, charp, 0000);
MODULE_PARM_DESC(message, "A string parameter for the Hello World module With a pinch of panic");

static int __init custom_init(void) {
	printk(KERN_INFO "Hello world Modified!! Parameter message: %s\n", message);
	printk(KERN_ALERT "Kernel panic triggered by hello module\n");
	return 0;
}

static void __exit custom_exit(void) {
	printk(KERN_INFO "Goodbye World Modified!!\n");
}

module_init(custom_init);
module_exit(custom_exit);

MODULE_AUTHOR("MottiKumar Babu");
MODULE_DESCRIPTION("My very first patch for Hello World kernel module with string parameter with add-on Panic for kernel");
MODULE_LICENSE("GPL");
