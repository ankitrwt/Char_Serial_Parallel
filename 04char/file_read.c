#include "header.h"
#include "var_defination.h"
//#include "file_op.h"

ssize_t read_dev(struct file *filep, char __user *buffer, size_t size, loff_t *bsize)
{
	struct scull_dev *ldev;
	struct scull_qset *lqset;
	long could_not_copied;

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif

	ldev = filep->private_data;
	if(!ldev)
	{
		#ifdef DEBUG
		printk(KERN_ERR "no device found\n");
		#endif
		goto OUT;
	}
	lqset = ldev->data;
	if(!lqset)
	{
		#ifdef DEBUG
		printk(KERN_ERR "no qset found\n");
		#endif
		goto OUT;	
	}
	if(!lqset->data)
	{
		#ifdef DEBUG
		printk(KERN_ERR "no item found\n");
		#endif
		goto OUT;	
	}

	if(!lqset->data[0])
	{
		#ifdef DEBUG
		printk(KERN_ERR "no data found\n");
		#endif
		goto OUT;	
	}

	could_not_copied = copy_to_user(buffer,lqset->data[0],size);
	if(could_not_copied == 0)
	{
		#ifdef DEBUG
		printk(KERN_ERR "copy_to_read() success\n");
		#endif
	}
	else
	{
		#ifdef DEBUG
		printk(KERN_ERR "no of bytes copied %lu\n",(size - could_not_copied));
		#endif
	}


	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

return (size - could_not_copied);

OUT:	
	return -1;
}

