
extern dev_t devno;
extern unsigned int major_no,minor_no;
extern struct scull_dev *dev[NOD];
extern struct file_operations fops;
//extern struct scull_dev->struct cdev;
extern int quantum,qset,nod;
extern long size;
extern struct proc_dir_entry *my_proc_file;


int open_dev (struct inode *, struct file *);
int close_dev (struct inode *, struct file *);
ssize_t write_dev (struct file *, const char __user *, size_t, loff_t *);
ssize_t read_dev (struct file *, char __user *, size_t, loff_t *);
long unlocked_ioctl_dev (struct file *, unsigned int, unsigned long);
int callback_read_proc(char *, char ** , off_t , int ,int * , void * );
extern struct file_operations fops;

extern struct proc_dir_entry *create_proc_entry(const char *name, umode_t mode,struct proc_dir_entry *parent);


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



