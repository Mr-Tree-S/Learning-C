#include <stdio.h>


int a[1000] = {0};
int b[1000] = {0};

int inarray()
{
	int n;
	int i = 0;
	while (~scanf("%d",&n) && n != 0) {
		a[i] = n;
//		printf("%d\n", a[i]);
//		printf("%d\n", i);
		i++;
	}
	return 0;
}

int deal()
{
	int j = 0;
	while (a[j] && j < 1000) {
		b[a[j]]++;
//		printf("%d\n", a[j]);
		j++;
	}
	return 0;
}

int outarray()
{
	int k;
	for (k=0; k<1000; k++) {
		if (b[k] != 0)
		printf("%d\n", k);
	}
	return 0;
}

int main()
{
	inarray();

	deal();

	outarray();

	return 0;
}
