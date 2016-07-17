#include "header.h"
#include "var_defination.h"
//#include "file_op.h"

//extern struct file *filep;
ssize_t write_dev(struct file *filep, const char __user *buffer, size_t size, loff_t *bsize)
{
long could_not_copy;
struct scull_dev  *ldev;
struct scull_qset *dptr;

int num_of_item,num_of_qset,l,i,x,quanta;
int next_four_char,char_wsuccess;
size_t lsize;
char temp_buf[] = "\0\0\0\0";

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

	i = 0;
	next_four_char = 0;
	char_wsuccess = 0;
	lsize = size;

	num_of_item = size / (ldev->qset * ldev->quantum);
	if(size % (ldev->qset * ldev->quantum))
		num_of_item++;

	num_of_qset = size / ldev->quantum;
	if(size % ldev->quantum)
		num_of_qset++;
		
		
	#ifdef DEBUG
	printk(KERN_INFO "num_of_item: %d\tnum_of_qset: %d\n",num_of_item,num_of_qset);
	#endif

	down(&ldev->sem);

	for(l = 0;l < num_of_item;l++)
	{
		if(l==0)
		{
			ldev->data = (struct scull_qset *)kmalloc(sizeof(struct scull_qset) , GFP_KERNEL);
			if(!ldev->data)
			{
				#ifdef DEBUG
				printk(KERN_ERR "scull_qset kmalloc() fails\n");
				#endif
				goto OUT;
			}
			memset(ldev->data,'\0',sizeof(struct scull_qset));
			dptr = ldev->data;
			dptr->data = (void **)kmalloc(sizeof(char *) * ldev->qset,GFP_KERNEL);
			if(!dptr->data)
			{
				#ifdef DEBUG
				printk(KERN_ERR "void *data kmalloc() fails\n");
				#endif
				goto OUT;
			}
			memset(dptr->data,'\0',sizeof(char) * ldev->qset);
		}
		else
		{
			dptr->next = (struct scull_qset *)kmalloc(sizeof(struct scull_qset) , GFP_KERNEL);
			if(!dptr->next)
			{
				#ifdef DEBUG
				printk(KERN_ERR "scull_qset kmalloc() fails\n");
				#endif
				goto OUT;
			}
			memset(dptr->next,'\0',sizeof(struct scull_qset));
			dptr = dptr->next;
			dptr->data = (void **)kmalloc(sizeof(char *) * ldev->qset,GFP_KERNEL);
			if(!dptr->data)
			{
				#ifdef DEBUG
				printk(KERN_ERR "void *data kmalloc() fails\n");
				#endif
				goto OUT;
			}
			memset(dptr->data,'\0',sizeof(char) * ldev->qset);
		
		}
	}
	dptr = ldev->data;	
	
	for(l = 0;l < num_of_qset ; l++)
	{
		
		if(lsize >= ldev->quantum)
			quanta = ldev->quantum;
		else
			quanta = lsize;

		dptr->data[i] = (void **)kmalloc(ldev->quantum * sizeof(char),GFP_KERNEL);
		if(!dptr->data[i])
		{	
			#ifdef DEBUG
			printk(KERN_INFO "quantum kmalloc fails\n");
			#endif
			goto OUT;
		}
		memset(dptr->data[i],'\0',ldev->quantum * sizeof(char));

		could_not_copy = copy_from_user(dptr->data[i],buffer + next_four_char,quanta);
		if(could_not_copy != 0)
		{	
			#ifdef DEBUG
			printk(KERN_INFO "copy_from_user() fails Bytes not wrote : %lu\n",could_not_copy);
			#endif

		}
		else
		{
			for(x=0;x<4;x++)
				temp_buf[x] = (char)  *((char *)(dptr->data[i]) + x);

			#ifdef DEBUG
			printk(KERN_INFO "copy_from_user() success %d: %s\n",i,temp_buf);
			#endif	
		}

		if(i == (ldev->qset - 1))
		{
			if(dptr->next)
				dptr = dptr->next;
			i = 0;
		}
		else
			i++;
		next_four_char += quanta; 
		char_wsuccess = char_wsuccess + (quanta - could_not_copy);
		lsize = lsize - ldev->quantum;
		#ifdef DEBUG
		printk(KERN_INFO "next_four_char: %d, char_wsuccess: %d",next_four_char,char_wsuccess);
		#endif

	}
	
	ldev->size = char_wsuccess;
	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif
up(&ldev->sem);	
return char_wsuccess;

OUT:	
	return -1;	
}

