#include "header.h"
#include "var_defination.h"
//#include "file_op.h"

ssize_t read_dev(struct file *filep, char __user *buffer, size_t size, loff_t *off)
{
	struct scull_dev *ldev;
	struct scull_qset *lqset;
	long could_not_copied;
//	int num_of_item,num_of_qset;
	int char_rsuccess,i,next_four_char,x,y,quanta,q_pos,s_pos;
	char temp_buf[4];

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	printk(KERN_INFO "filep->fpos: %d\n",(int)filep->f_pos);
	printk(KERN_INFO "*pos: %d\n",(int)*off);
	#endif

	ldev = filep->private_data;
	if(!ldev)
	{
		#ifdef DEBUG
		printk(KERN_ERR "no device found\n");
		#endif
		goto OUT;
	}
	
	s_pos = (int)*off / ldev->quantum;
	q_pos = (int)*off % ldev->quantum;

	#ifdef DEBUG
	printk(KERN_INFO "s_pos: %d,q_pos: %d\n",s_pos,q_pos);
	#endif


	i = s_pos;
	char_rsuccess = 0;
	next_four_char = 0;
	quanta = ldev->quantum;

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
		while(((char)*((char *)(lqset->data[i] + x)) != '\0') && (x<ldev->quantum))x++;
		if(x ==  ldev->quantum)
			quanta = ldev->quantum;
		else
			quanta = x;
		
		could_not_copied = copy_to_user((buffer + next_four_char),(lqset->data[i] + q_pos),(quanta - q_pos));
		if(could_not_copied == 0)
		{
			for(x=next_four_char,y=0;x<(char_rsuccess + (quanta - q_pos));x++,y++)
				temp_buf[y] = (char)*(buffer + x);

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
		
		char_rsuccess = char_rsuccess + ((quanta - q_pos) - could_not_copied);
		next_four_char += (quanta - q_pos);
		
		*off = *off + ((quanta - q_pos) - could_not_copied);
		filep->f_pos = *off;
		q_pos = 0;

		#ifdef DEBUG
		printk(KERN_INFO "next_four_char: %d, char_rsuccess: %d",next_four_char,char_rsuccess);
		printk(KERN_INFO "filep->fpos: %d\n",(int)filep->f_pos);
		printk(KERN_INFO "*pos: %d\n",(int)*off);
		#endif
	}

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	printk(KERN_INFO "filep->fpos: %d\n",(int)filep->f_pos);
	printk(KERN_INFO "*pos: %d\n",(int)*off);
	#endif

return char_rsuccess;
OUT:	
	return -1;
}

