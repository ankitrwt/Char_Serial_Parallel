#include "header.h"
#include "var_defination.h"
#include "ioctl_header.h"
//#include "file_op.h"

//extern struct file *filep;
long unlocked_ioctl_dev(struct file *filep, unsigned int cmd, unsigned long arg)
{
int ret = 0;
struct scull_dev  *ldev;
//struct scull_qset *dptr;

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

	switch(cmd)
	{
	case RESET:
		ldev->quantum = quantum = QUANTUMSIZ;
		ldev->qset = qset = QSETSIZ;
		ldev->size = size = DATASIZ;
	break;
	case GETREGISTERSIZE:
		put_user(ldev->quantum,(int __user *)arg);
	break;
	case SETREGISTERSIZE:
	//	ret = get_user(ldev-quantum,(int __user *)arg);
		if(ret < 0)
		{
			goto OUT;
		}
	break;
	case GETNOOFREGISTERS:
		put_user(ldev->size,(int __user *)arg);

	break;
	case SETNOOFREGISTERS:
	//	ret = get_user(ldev-size,(int __user *)arg);
		if(ret < 0)
		{
			goto OUT;
		}
	break;
	case GETBAUDRATE:

	break;
	case SETBAUDRATE:

	break;
	}

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

return 0;

OUT:	
	return -1;	
}

