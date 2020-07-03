#include <stdio.h>


void main()
{
	int a, b, c, max;
	
	printf("please input a,b,c: \n");
	scanf("%d %d %d", &a, &b, &c);
	
	max=a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	
	printf("The max number is %d \n", max);
	
	return;
}
