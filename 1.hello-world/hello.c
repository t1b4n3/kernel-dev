#include <linux/init.h>
#include <linux/module.h>


static int hello_world(void) {
	printk(KERN_INFO "Hello Kernel World\n");
	return 0;
}

static void goodbye_world(void) {
	printk(KERN_INFO "Goodbye Kernel World\n");
}

module_init(hello_world);
module_exit(goodbye_world);

MODULE_LICENSE("t1b4n3");

