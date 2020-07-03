#include <stdio.h>
void main()
{
	int a[4]={0,1,2,3};
	int *p,*q;
	p=a;
	q=&a[0];
	printf("%d,%d\n",p,q);
	printf("%d,%d\n",*p,*q);

	a[0]=6;
	printf("%d,%d\n",p,q);
	printf("%d,%d\n",*p,*q);
}

