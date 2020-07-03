#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	int srcid,dstid;
	unsigned char buf[1024];
	int readlen;
	
	memset(buf,0,1024);
	
	srcid=open("/home/s/workspace/Learning-C/learn-IO/src/open.c",O_RDWR);
	if(srcid<0){
		printf("open file error!\n");
	}

	dstid=open("/home/s/workspace/Learning-C/learn-IO/src/open.c.bak",O_RDWR | O_CREAT, 0777);
	printf("dstid=%d\n",dstid);
	if(dstid<0){
		printf("error!!!\n");
	}

	readlen=read(srcid,buf,1024);
	printf("date length:%d\n",readlen);

	printf("date content:\n");
	printf("%s",buf);

	write(dstid,buf,readlen);

	close(srcid);
	close(dstid);
}
