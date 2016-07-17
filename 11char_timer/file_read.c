#include "header.h"
#include "var_defination.h"
//#include "file_op.h"

extern unsigned long jiffers;

ssize_t read_dev(struct file *filep, char __user *buffer, size_t size, loff_t *bsize)
{
	struct scull_dev *ldev;
	struct scull_qset *lqset;
	long could_not_copied;
	unsigned long start,end;
//	unsigned long time;
//	int num_of_item,num_of_qset;
	int char_rsuccess,i,next_four_char,x,quanta;
	char temp_buf[4];

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif

	rdtscll(start);
//	jstart = jiffies;//+ HZ;
//	#ifdef DEBUG
//	printk(KERN_INFO "start jiffie = %lu\n",jstart);
//	#endif

	ldev = filep->private_data;
	if(!ldev)
	{
		#ifdef DEBUG
		printk(KERN_ERR "no device found\n");
		#endif
		goto OUT;
	}

	i = 0;
	char_rsuccess = 0;
	next_four_char = 0;
/*
	num_of_item =	size / (ldev->qset * ldev->quantum);
	if(size%(ldev->qset *ldev->quantum))
		num_of_item++;

	num_of_qset = size / ldev->quantum;
	if(size%ldev->quantum)
		num_of_qset++;
		
	#ifdef DEBUG
	printk(KERN_INFO "num_of_item: %d\tnum_of_qset: %d\n",num_of_item,num_of_qset);
	#endif
*/

	lqset = ldev->data;
	
	if(!lqset)
	{
		#ifdef DEBUG
		printk(KERN_ERR "no qset found\n");
		#endif
		goto OUT;	
	}

	while(lqset->data[i] != '\0')
	{
		if(!lqset->data)
		{
			#ifdef DEBUG
			printk(KERN_ERR "no item found\n");
			#endif
			goto OUT;	
		}

		if(!lqset->data[i])
		{
			#ifdef DEBUG
			printk(KERN_ERR "no data found\n");
			#endif
			goto OUT;	
		}

		x = 0;
		while(((char)*((char *)(lqset->data[i] + x)) != '\0') && (x<4))x++;
		if(x == 4)
			quanta = ldev->quantum;
		else
			quanta = x;
		
		could_not_copied = copy_to_user((buffer + next_four_char),lqset->data[i],quanta);
		if(could_not_copied == 0)
		{
			for(x=0;x<4;x++)
				temp_buf[x] = (char)  *((char *)(lqset->data[i]) + x);

			#ifdef DEBUG
			printk(KERN_ERR "copy_to_read() success: %d %s\n",i,temp_buf);
			#endif
		}
		else
		{
			#ifdef DEBUG
			printk(KERN_ERR "Partially read %lu\n",(ldev->quantum - could_not_copied));
			#endif
		}


		if(i == (ldev->qset - 1))
		{
			if(lqset->next)
				lqset = lqset->next;
			else
				return char_rsuccess;
				
			i = 0;
		}
		else
			i++;
	
		#ifdef DEBUG
		printk(KERN_INFO "buffer: %s\n ",buffer + next_four_char);
		#endif

		char_rsuccess = char_rsuccess + (quanta - could_not_copied);
		next_four_char += quanta;

		#ifdef DEBUG
		printk(KERN_INFO "next_four_char: %d, char_rsuccess: %d",next_four_char,char_rsuccess);
		#endif

	}


	rdtscll(end);

//	jend = jiffies;
//	#ifdef DEBUG
//	printk(KERN_INFO "end jiffie = %lu\n",jend);
//	#endif

//	time = jend - jstart;
	//time = time_after((unsigned long)end,(unsigned long)start);
	
//	#ifdef DEBUG
//	printk(KERN_INFO "Time: %lu - %lu = %d\n",jend,jstart,time);
//	#endif

	#ifdef DEBUG
	printk(KERN_INFO "Time: %lu - %lu = %lu\n",end,start,(end - start));
	#endif

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

return char_rsuccess;
OUT:	
	return -1;
}

