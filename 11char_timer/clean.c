#include "header.h"
#include "var_defination.h"

//extern struct scull_dev *dev;
/*
extern struct scull_qset{
	void **data;
	struct scull_qset *next;
};
	      
extern struct scull_dev{
	struct scull_qset *data;
	int quantum;
	int qset;
	unsigned long size;
	unsigned int access_key;
	struct semaphore sem;
	struct cdev c_dev;
};
*/     
extern unsigned long jstart, jend;

static void __exit exit_function(void)
{
int l;
	struct timespec timestruct;
	unsigned long time;

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif
	
	for(l = 0;l < NOD;l++)
	{
		cdev_del(&dev[l]->c_dev);
		kfree(dev[l]);
	}

	unregister_chrdev_region(devno,NOD);
	rdtscll(jend);//jend = get_jiffies_64();

	time = jend - jstart; //time_after(jend,jstart);

	jiffies_to_timespec(time ,&timestruct);

	#ifdef DEBUG
	printk(KERN_INFO "Time: %lu, %lu",time,timestruct.tv_nsec);//(jend - jstart));
	#endif	
	
	#ifdef DEBUG
	printk(KERN_WARNING "End: %s\n",__func__);
	#endif	
}

module_exit(exit_function);

