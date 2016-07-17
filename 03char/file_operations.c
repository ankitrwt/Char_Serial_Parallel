#include "header.h"
#include "file_op.h"

 //int (*open) (struct inode *, struct file *);
 //int (*release) (struct inode *, struct file *);
struct file_operations fops = {
	open : open_dev,
	release : close_dev
};
 
int open_dev(struct inode * node,struct file *mydev)
{
	#ifdef DEBUG
	printk(KERN_INFO "file open\n");
	#endif


return 0;
}

int close_dev(struct inode *node,struct file *mydev)
{
	#ifdef DEBUG
	printk(KERN_INFO "file close\n");
	#endif

return 0;
}


