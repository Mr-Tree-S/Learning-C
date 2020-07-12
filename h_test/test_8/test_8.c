#include <stdio.h>


int deal(int n)
{
	for (int i = 2; i < n; i++) {
		if (n%i == 0)
			return i;
	}
	return -1;
}


int main()
{
	int n;
	scanf("%d", &n);

	int i = deal(n);
	if (i != -1)
		printf("%d %d\n", i, n/i);
	else
		printf("-1 -1\n");

	return 0;
}
