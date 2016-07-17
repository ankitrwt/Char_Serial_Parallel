#include "header.h"
#include "var_defination.h"
//#include "file_op.h"

//extern struct file *filep;
ssize_t write_dev(struct file *filep, const char __user *buffer, size_t size, loff_t *bsize)
{
int could_not_copy;
struct scull_dev  *ldev;
struct scull_qset *dptr;

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif

	ldev = filep->private_data;
	if(!ldev)
	{
		#ifdef DEBUG
		printk(KERN_INFO "ldev is NULL\n");
		#endif
		goto OUT;
	}


	ldev->data = (struct scull_qset *)kmalloc(sizeof(struct scull_qset) , GFP_KERNEL);
	if(!ldev->data)
	{
		#ifdef DEBUG
		printk(KERN_ERR "scull_qset kmalloc() fails\n");
		#endif
		goto OUT;
	}
	memset(ldev->data,'\0',sizeof(struct scull_qset));

	dptr = ldev->data;

	dptr->data = (void **)kmalloc(sizeof(char *) * ldev->qset,GFP_KERNEL);
	if(!dptr->data)
	{
		#ifdef DEBUG
		printk(KERN_ERR "void *data kmalloc() fails\n");
		#endif
		goto OUT;
	}
	memset(dptr->data,'\0',sizeof(char) * ldev->qset);

	dptr->data[0] = (void **)kmalloc(ldev->quantum,GFP_KERNEL);
	if(!dptr->data[0])
	{	
		#ifdef DEBUG
		printk(KERN_INFO "quantum kmalloc fails\n");
		#endif
		goto OUT;
	}
	memset(dptr->data[0],'\0',ldev->quantum);

	could_not_copy = copy_from_user(dptr->data[0],buffer,size);
	if(could_not_copy != 0)
	{	
		#ifdef DEBUG
		printk(KERN_INFO "copy_from_user() fails\n");
		#endif

		//return (size - could_not_copy);
	}
	else
	{
		#ifdef DEBUG
		printk(KERN_INFO "copy_from_user() success\n");
		#endif	
	}

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif
	
return (size - could_not_copy);

OUT:	
	return -1;
}

