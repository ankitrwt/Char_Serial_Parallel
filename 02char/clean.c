#include "header.h"
//#include "file_op.h"

extern unsigned int major_no;

static void __exit exit_function(void)
{
//int ret;
	unregister_chrdev(major_no,DEV_NAME);

	#ifdef DEBUG
	printk(KERN_WARNING " exit success\n");
	#endif
	
}

module_exit(exit_function);

