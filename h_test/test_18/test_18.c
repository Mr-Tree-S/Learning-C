#include <stdio.h>
#include <stdlib.h>

typedef struct boy {
	int high;
	int abs;
}Boy;

void sort_high(Boy *a, int n)
{
	Boy temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++) {
			if (a[j].high > a[j+1].high) {
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void sort_abs(Boy *a, int n)
{
	Boy temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++) {
			if (a[j].abs > a[j+1].abs) {
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int x_h;
	int n;
	scanf("%d %d", &x_h, &n);

	Boy a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].high);
		a[i].abs = abs(a[i].high-x_h);
	}

	sort_high(a, n);
	sort_abs(a, n);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i].high);
	printf("\n");

	return 0;
}
