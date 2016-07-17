#include "header.h"
#include "var_defination.h"


int trim_dev(struct scull_dev * dev)
{
	int l;

	struct scull_dev *ldev;
	struct scull_qset *lqset,*sec_last;

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif

	sec_last = NULL;
	ldev = dev;

/*
	for(lqset = ldev->data; lqset; lqset = sec_last)
	{
		if(lqset->data)
		{
			for(l = 0; l < ldev->qset; l++)
				kfree(lqset->data[l]);
			
			kfree(lqset->data);
			lqset->data = NULL;
			
		}
		sec_last = lqset->next;
		kfree(lqset);
	}

*/

	if(!ldev){
		#ifdef DEBUG
		printk(KERN_INFO "No device found\n");
		#endif
		goto OUT;
	}

	lqset = ldev->data;
	if(!lqset){
		#ifdef DEBUG
		printk(KERN_INFO "Nothing to trim");
		#endif
		goto OUT;
	}

	while(sec_last != ldev->data)
	{
		l = 0;
		sec_last = lqset;
		while(lqset->next != NULL){
			sec_last = lqset;
			lqset = lqset->next;
			l++;
			#ifdef DEBUG
			printk(KERN_INFO "remaining qset size %d\n",l);
			#endif
		}

		for(l = ldev->qset - 1;l >= 0;l--){
			if(sec_last->data[l] != NULL)
			{
				kfree(sec_last->data[l]);
				sec_last->data[l] = NULL;

				#ifdef DEBUG
				printk(KERN_INFO "quantum release\n");
				#endif
			}
		}

		kfree(sec_last->data);
		sec_last->data = NULL;
		
		#ifdef DEBUG
		printk(KERN_INFO "data release\n");
		#endif

		//lqset = sec_last;
		kfree(sec_last);
		if(ldev->data != sec_last)
		{
			lqset = ldev->data;
			while(lqset->next != sec_last){
				lqset = lqset->next;
			}
			lqset->next = NULL;
		}
		else
		{
			ldev->data = NULL;
		}

		lqset = ldev->data;
	}
	
	sec_last = NULL;
	ldev = NULL;
	lqset = NULL;

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

return 0;

OUT:
	return -1;
}
