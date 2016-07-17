#include "header.h"
#include "var_defination.h"
#include "ioctl_header.h"
//#include "file_op.h"

//extern struct file *filep;
int callback_read_proc(char * page, char ** start, off_t offset, int count,int * eof, void * data)
{
int len;

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif

	len = 0;
	offset = 0;
	*eof = 1;
	count = 0;

	len += sprintf(page+len,"Quantum Size:%d\n",(int)quantum);

	len += sprintf(page+len,"Qset Size:%d\n",(int)qset);

	len += sprintf(page+len,"Data Size:%d\n",(int)size);
	
	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

return len;

}

