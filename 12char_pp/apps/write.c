#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int write_func()
{
int ret,fd;
unsigned char ch;
//char buffer[] = "...NOW ITS TIME TO WRITE BIG STRING ON SCULL... NOW ITS TIME TO WRITE BIG STRING ON SCULL... NOW ITS TIME TO WRITE BIG STRING ON SCULL...";
	fd = open("./node",O_WRONLY);
	if(fd == -1)
	{
		perror("open fails\n");
	//	return -1;
	}

	printf("Enter Byte: ");
	scanf("%c",&ch);
	ret = write(fd,&ch,1);
	printf("wrote bytes: %d\n",ret);
	if(ret == -1){
		perror("write() fails\n");
		return -1;
	}

	close(fd);

return 0;
}
