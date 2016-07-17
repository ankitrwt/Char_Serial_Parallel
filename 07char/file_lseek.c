#include "header.h"
#include "var_defination.h"
//#include "file_op.h"

loff_t lseek_dev(struct file *filep, loff_t off, int whence)
{
struct scull_dev *ldev;
loff_t newpos;
	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif

	ldev = filep->private_data;
	if(!ldev)
	{
		#ifdef DEBUG
		printk(KERN_ERR "no device found\n");
		#endif
		return off;
	}


	switch(whence){
	
	case SEEK_SET:
		#ifdef DEBUG
		printk(KERN_INFO "SEEK_SET\n");
		#endif
		
		newpos = off;
		
		break;
	
	case SEEK_CUR:
		#ifdef DEBUG
		printk(KERN_INFO "SEEK_CUR\n");
		#endif
		
		newpos = filep->f_pos + off;

		break;

	case SEEK_END:
		#ifdef DEBUG
		printk(KERN_INFO "SEEK_END\n");
		#endif
		
		newpos = ldev->size + off;

		break;
	default:
		#ifdef DEBUG
		printk(KERN_INFO "WRONG WHENCE\n");
		#endif
		
		return -EINVAL;
		break;
	}

		if(off < 0)return -EINVAL;
		filep->f_pos = newpos;

	#ifdef DEBUG
	printk(KERN_INFO "filep->fpos: %d\n",(int)filep->f_pos);
	printk(KERN_INFO "*pos: %d\n",(int)off);
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

return newpos;
}

