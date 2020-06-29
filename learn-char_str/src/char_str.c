#include <stdio.h>

int main(void)
{
	int i=0;
	char *s="Hello";
	char *s2="Hello";
	char s3[6]="Hello";


	printf("s =%p\n",s);
	printf("s2=%p\n",s2);
	printf("s3=%p\n",s3);


	//printf("s =%s\n",*s);
	printf("s3=%c\n",s3[0]);


	return 0;
}
