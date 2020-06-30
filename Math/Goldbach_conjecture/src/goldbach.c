#include <stdio.h>
#include <stdlib.h>


int prime(int n)
{
	int m;
	int count = 0;
	for (m = 2; m <= n-1; m++) {
		if (n%m == 0) {
			count++;
			break;
		}
	}

	return count;
}

int main()
{
	int max;
	int a;
	int i, j;
	int count1, count2;

	printf("Please input the max number: ");
	scanf("%d", &max);
	for (a = 4; a <= max; a = a+2) {
		for (i = 2; i <= a/2; i++) {
			count1 = 0;
			count1 = prime(i);

			if (count1 == 0) {
				j = a-i;
				count2 = 0;
				count2 = prime(j);
				if (count2 == 0) {
					printf("%d=%d+%d\n", a, i, j);
					break;
				}
			}
		}
	}

	return 0;
}
