#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>

static dev_t dev_id;
static struct cdev *mydev;

ssize_t mydev_read(struct file *file, char __user *data, size_t size, loff_t * loff)
{
    printk("mydev_read\n");
    
    return 0;
}

ssize_t mydev_write(struct file *file, const char __user *data, size_t size, loff_t *loff)
{
    printk("mydev_write\n");

    return 0;
}

int mydev_open(struct inode *inode, struct file *file)
{
    printk("mydev_open\n");

    return 0;
}

/* 文件操作集合 */
static struct file_operations mydev_fops = {
	.owner = THIS_MODULE,
    .read   = mydev_read,
    .open   = mydev_open,
    .write  = mydev_write,
};

static __init int mydev_init(void)
{
    /* 申请设备号 */
    alloc_chrdev_region(&dev_id, 1, 1, "mydev");

    /* 分配字符设备 */
    mydev = cdev_alloc();

    /* 设置字符设备 */
    cdev_init(mydev, &mydev_fops);

    /* 注册字符设备 */
    cdev_add(mydev, dev_id, 1);

    /* 打印申请到的主次设备号 */
    printk("major:%d; minor:%d\n", MAJOR(dev_id), MINOR(dev_id));

    return 0;
}

static __exit void mydev_exit(void)
{
    cdev_del(mydev);
    kfree(mydev);
    unregister_chrdev_region(dev_id, 1);
}

module_init(mydev_init);
module_exit(mydev_exit);

MODULE_LICENSE("GPL");
