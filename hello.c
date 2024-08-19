#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

static int __init custom_init(void) {
	printk(KERN_INFO "Hello world Modified!!");
	return 0;
}
static void __exit custom_exit(void) {
	printk(KERN_INFO "Goodbye World Modified!!");
}

module_init(custom_init);
module_exit(custom_exit);

MODULE_AUTHOR("MottiKumar Babu");
MODULE_DESCRIPTION("My very first patch for Hello World kernel module");
MODULE_LICENSE("GPL");

