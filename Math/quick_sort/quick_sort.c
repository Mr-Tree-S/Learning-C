#include <stdio.h>


void quick_sort(int *a, int low, int high)
{
	int i = low;
	int j = high;
	int key = a[low];

	if (i >= j)
		return;

	while (i < j) {
		while (i < j && key <= a[j]) {
			j--;
		}
		a[i] = a[j];

		while(i < j && key >= a[i]) {
			i++;
		}
		a[j] = a[i];
	}

	a[i] = key;
	quick_sort(a, low, i-1);
	quick_sort(a, i+1, high);
}


int main()
{
	int i;
	int a[] = {0, 8, 1, 24, 2, 7, 15, 12, 26, 99};

	quick_sort(a, 0, 9);

	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
