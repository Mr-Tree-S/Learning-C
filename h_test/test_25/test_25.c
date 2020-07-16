#include <stdio.h>


int main()
{
	int k;
	int n;
	int m;
	scanf("%d %d %d", &k, &n, &m);

	int y;
	int a[100];
	int count = 0;
	do {
		y = k%m;
		k = k/m;
		a[count++] = y;
	} while(k > 0);

	int sum = 0;
	for (int j = count-1; j >= 0; j--) {
		if (a[j] == n)
			sum++;
	}
	printf("%d\n", sum);

	return 0;
}
