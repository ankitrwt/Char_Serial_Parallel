#include "header.h"
#include "file_op.h"

dev_t devno;
unsigned int major_no,minor_no;
// int quantum,qset,dsize;
struct scull_dev scull;

static int __init init_function(void)
{
int ret;
	//MAJOR(dev_no);
	//MINOR(dev_no);

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__FILE__);
	#endif
	//extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *);						
	//major_no = register_chrdev(0,DEV_NAME,&fops);
	
	scull.quantum = QUANTUMSIZ;
	scull.qset = QSETSIZ;
	scull.size = DEVICESIZ;
	scull.c_dev.owner = THIS_MODULE;
	scull.c_dev.ops = &fops;
	scull.c_dev.count= NOD;

	ret = alloc_chrdev_region(&devno,minor_no,NOD,DEV_NAME);
	if(ret < 0)
	{
		#ifdef DEBUG
		printk(KERN_ALERT "alloc_chrdev_region() fails\n");
		#endif
		return ret;
	}
	major_no = MAJOR(devno);
	#ifdef DEBUG
	printk(KERN_INFO "major_no: %d\n",major_no);
	#endif
	
//	dev = kmalloc(sizeof(struct cdev) * NOD);
//	memset(dev,'\0',sizeof(struct cdev));



	//minor_no = 1;	
	//MKDEV(major_no,minor_no);
	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__FILE__);
	#endif

return 0;
}

module_init(init_function);

