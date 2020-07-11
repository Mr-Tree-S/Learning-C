#include <stdio.h>
#include <math.h>


int main()
{
	int sum;
	int a;
	scanf("%d %d", &sum, &a);

	double b;
	b = sum/(pow(26, a)*10);
	int B = b;

	if (b-B > 0)
	printf("%d\n", ++B);
	else
	printf("%d\n", B);

	return 0;
}
