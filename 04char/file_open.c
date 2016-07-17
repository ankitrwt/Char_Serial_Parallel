#include "header.h"
#include "var_defination.h"
//#include "file_op.h"

//struct file *filep;


int open_dev(struct inode * inode,struct file *filep)
{
	struct scull_dev *ldev;
	
	ldev = dev[0];
	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif

	ldev = container_of(inode->i_cdev,struct scull_dev,c_dev);
	if(!ldev)
	{
		printk(KERN_ERR "container_of() fails\n");
		goto OUT;
	}

	if((filep->f_flags & O_ACCMODE) == O_WRONLY)
	{
	
	
	}
//------------------------------------------------------------------------
//------------------TRIM DATA
//------------------------------------------------------------------------

filep->private_data = ldev;

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif
return 0;

OUT:	
	return -1;
}

