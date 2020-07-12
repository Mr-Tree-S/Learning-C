#include <stdio.h>


int main()
{
	int sum = 0;
	int n[180] = {0};
	int day;

	scanf("%d", &day);

	for (int i = 1; i <= day; i++) {
		n[i] = i/3;
		sum = sum + 2*n[i-1];
	}

	printf("%d\n", sum);

	return 0;
}
