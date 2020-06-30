#include <stdio.h>

int main()
{
	int n, i;

	scanf("%d", &n);
	int F = 1;

	for (i = 2; i <= n; i++) {
		F *= i;
	}
	
	printf("factorial=%d\n", F);
	
	return 0;
}
