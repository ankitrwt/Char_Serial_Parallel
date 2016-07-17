#include<stdio.h>


int menu()
{
int choice;
	printf("\nchoose from following options\n");
	printf("1. write\n");
	printf("2. read\n");
	printf("3. lseek\n");
	printf("4. ioctl\n");
	printf("5. exit\n");
	printf("\nEnter: ");
	scanf("%d",&choice);
	
return choice;
}
