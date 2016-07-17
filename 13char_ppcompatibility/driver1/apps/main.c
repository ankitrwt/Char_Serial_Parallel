#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include"decleration.h"

int main()
{
int ret,choice;

while(1)
{
	choice = menu();

	switch(choice)
	{
		case 1:
			write_func();	
		break;
		case 2:
			read_func();
		break;
		case 3:
			lseek_func();
		break;
		case 4:
			ioctl_func();
		break;
		case 5:
			exit(EXIT_SUCCESS);
		break;
		default:
			printf("Invalid Choice\n");
	
	}

}
//return 0;
}
