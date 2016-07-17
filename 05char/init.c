#include "header.h"
//#include "file_op.h"
#include "var_defination.h"

struct file_operations fops = {
	open : open_dev,
	release : close_dev,
	write : write_dev,
	read : read_dev
};

dev_t devno,temp_devno;
unsigned int major_no,minor_no;
struct scull_dev *dev[NOD];
//struct file_operations fops = {};

int quantum,qset,nod;
long size;

static int __init init_function(void)
{
int ret,l;
	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif	
	quantum = QUANTUMSIZ;
	qset = QSETSIZ;
	size = DEVICESIZ;
	minor_no = MINOR_NO; 
//	scull.c_dev.owner = THIS_MODULE;
//	scull.c_dev.ops = &fops;
	nod = NOD;

	ret = alloc_chrdev_region(&devno,minor_no,NOD,DEV_NAME);		// if i give minor no 0 here thn alloc_chrdev_region will register only for minor_no 0 ??????
	if(ret < 0)
	{
		#ifdef DEBUG
		printk(KERN_ALERT "alloc_chrdev_region() fails\n");
		#endif
		return ret;
	}
		temp_devno = devno;
		major_no = MAJOR(temp_devno);
	
	for(l = 0;l< NOD; l++)
	{
		temp_devno = MKDEV(major_no,minor_no + l);	//devno changed here which is causing trouble in unregistre_chrdev_region due to which allocated devno device is not unregisterd?????????
	
		dev[l] = (struct scull_dev *)kmalloc(sizeof(struct scull_dev),GFP_KERNEL);
		memset(dev[l],'\0',sizeof(struct scull_dev));
		
		dev[l]->quantum = quantum;
		dev[l]->qset = qset;
		dev[l]->size = size;
		dev[l]->c_dev.owner = THIS_MODULE;
		dev[l]->c_dev.ops = &fops;
		dev[l]->c_dev.dev = temp_devno;
		dev[l]->c_dev.count = nod;
		
		//major_no = MAJOR(devno);
		//minor_no = MINOR(devno);

		cdev_init(&dev[l]->c_dev,&fops);

		ret = cdev_add(&dev[l]->c_dev,temp_devno,nod);
		if(ret <= -1){
			#ifdef DEBUG
			printk(KERN_ERR "cdev_add() fails\n");
			#endif
			return ret;
		}

		#ifdef DEBUG
		printk(KERN_INFO "major_no: %d minor_no: %d\n",MAJOR(temp_devno),MINOR(temp_devno));
		#endif
	
	}
	//minor_no = 1;	
	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

return 0;
}

module_init(init_function);

