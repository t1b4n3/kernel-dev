#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>


#define DEVICE_NAME "Interactive Char Device Driver"  

static int major;

static ssize_t cdev_read(struct file *filp, char __user *buffer, size_t len, loff_t *off) {
	printk(KERN_INFO "READING ...");
	char buf[0x20] = "HELLO USERLAND";
	copy_to_user(buffer, buf, strlen(buf));
	return 0;
}

static ssize_t cdev_write(struct file *filp, const char __user *buffer, size_t len, loff_t *off) {
	printk(KERN_INFO "WRITING...");
	char buf[0x30];
	copy_from_user(buf, buffer, strlen(buffer));
	printk(KERN_INFO "GOT : %s\n", buf);
	return 0;
}


static ssize_t cdev_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
   	 printk("Command: %d; Argument: %lx", cmd, arg);
    	return 0;
}



static struct file_operations fops = {
	.read = cdev_read,
	.write = cdev_write,
	.compat_ioctl = cdev_ioctl,
	.unlocked_ioctl = cdev_ioctl
};


static int __init char_init(void) {
	major = register_chrdev(0, DEVICE_NAME, &fops);
	if (major < 0) {
		printk(KERN_ALERT "[Char Device Driver] - Error registering chrdev\n");
		return major;
	}
	printk(KERN_INFO "[CHRDEV] Major Device Number = %d\n", major);
	return 0;
}

static void __exit char_exit(void) {
	unregister_chrdev(major, DEVICE_NAME);
}

module_init(char_init);
module_exit(char_exit);

MODULE_LICENSE("t1b4n3");
MODULE_AUTHOR("t1bn43");
