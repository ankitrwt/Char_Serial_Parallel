#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ioctl.h>
#include"ioctl_header.h"

int ioctl_func()
{
int ret,fd,choice,arg;

	fd = open("node",O_RDONLY);
	if(fd == -1)
	{
		perror("file open fails");
		goto OUT;
	}

	choice = ioctl_menu();

	switch(choice)
	{
	case 1:
		ret = ioctl(fd,RESET,&arg);
		if(ret != 0)
		{
			perror("IOCTL Reset");
			goto OUT;
		}
		else
		{
			printf("GOT: %d",arg);
		}
	break;
	case 2:
		ret = ioctl(fd,GETREGISTERSIZE,&arg);
		if(ret != 0)
		{
			perror("IOCTL get register size");
			goto OUT;
		}
		else
		{
			printf("REGISTER SIZE: %d",arg);
		}

	break;
	case 3:

		printf("Enter Register Size: ");
		scanf("%d",&arg);
		ret = ioctl(fd,SETREGISTERSIZE,&arg);
		if(ret != 0)
		{
			perror("IOCTL set register size");
			goto OUT;
		}

	break;
	case 4:
		ret = ioctl(fd,GETNOOFREGISTERS,&arg);
		if(ret != 0)
		{
			perror("IOCTL get no of registers");
			goto OUT;
		}
		else
		{
			printf("NO OF REGISTERS: %d",arg);
		}

	break;
	case 5:
		printf("Enter No of Register Size: ");
		scanf("%d",&arg);
		ret = ioctl(fd,SETNOOFREGISTERS,&arg);
		if(ret != 0)
		{
			perror("IOCTL set no of registers");
			goto OUT;
		}

	break;
	case 6:
		ret = ioctl(fd,GETBAUDRATE,&arg);
		if(ret != 0)
		{
			perror("IOCTL get baudrate");
			goto OUT;
		}
		else
		{
			printf("BAUDRATE: %d",arg);
		}

	break;
	case 7:
		ret = ioctl(fd,SETBAUDRATE,&arg);
		if(ret != 0)
		{
			perror("IOCTL set baudrate");
			goto OUT;
		}
		else

	break;
	case 8:
		exit(EXIT_SUCCESS);
	break;
	default:
		printf("Invalid Choice\n");
	
	}

return 0;

OUT:
	return -1;
}
