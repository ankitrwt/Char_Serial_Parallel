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

static void __exit exit_function(void)
{
int l;
	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif
	
	for(l = 0;l < NOD;l++)
	{
		cdev_del(&dev[l]->c_dev);
		kfree(dev[l]);
	}
	
	//remove_proc_entry("MyProc",NULL);
	unregister_chrdev_region(devno,NOD);

	#ifdef DEBUG
	printk(KERN_WARNING "End: %s\n",__func__);
	#endif	
}

module_exit(exit_function);

