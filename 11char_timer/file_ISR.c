#include "header.h"


extern struct timer_list timer;

void my_function(unsigned long data)
{

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s",__func__);
	#endif


	del_timer(&timer);	
	#ifdef DEBUG
	printk(KERN_INFO "End: %s",__func__);
	#endif
}

