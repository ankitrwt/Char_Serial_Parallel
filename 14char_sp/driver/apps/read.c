#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int read_func()
{
int ret,fd;
char ch;

//	memset(buffer,'\0',BUFSIZ);
	ch = '\0';
	fd = open("./node",O_RDONLY);
	if(fd == -1)
	{
		perror("open fails\n");
		return -1;
	}
	
	ret = read(fd,&ch,sizeof(char));
	printf("read byte: %d\n",ret);
	printf("got byte: %c\n",ch);
	if(ret == -1){
		perror("read() fails\n");
		return -1;
	}

	close(fd);

return 0;
}
