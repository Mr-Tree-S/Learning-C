#include <stdio.h>

int main(void)
{
	int i=0;
	char *s="Hello";
	char *s2="Hello";
	char s3[]="Hello";


	printf("s =%p\n",s);
	printf("s2=%p\n",s2);
	printf("s3=%p\n",s3);


	//printf("s =%s\n",*s);
	printf("s3=%s\n",s3);


	return 0;
}
