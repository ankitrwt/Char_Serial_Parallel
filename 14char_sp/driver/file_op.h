//extern int quantam
//extern dev_t devno;
//#include <linux/fs.h>
//int open_dev (struct inode *, struct file *);
//int close_dev (struct inode *, struct file *);

/*
int open_dev (struct inode *, struct file *);
int close_dev (struct inode *, struct file *);

extern struct file_operations fops = {
	open : open_dev,
	release : close_dev
};
*/
/*
struct cdev {
	struct kobject kobj;
	struct module *owner;
	const struct file_operations *ops;
	struct list_head list;
	dev_t dev;
	unsigned int count;
};


struct scull_qset{
	void **data;
	struct scull_qset *next;
};

struct scull_dev{
	struct scull_qset *data;
	int quantum;
	int qset;
	unsigned long size;
	unsigned int access_key;
	struct semaphore sem;
	struct cdev c_dev;
};
*/
