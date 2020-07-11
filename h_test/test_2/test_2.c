#include <stdio.h>
#include <string.h>

void create(int *a, int n)
{
	a[0] = 1;
	a[1] = 2;
	a[2] = 4;
	for (int i = 3; i < n; i++)
		a[i] = a[i-1]+a[i-2]+a[i-3];
}

int main()
{
	//	printf("%d %d\n", 'a', 'z');

	int m = 50;
	int a[m];
	create(&a, m);

	int n;
	char str[m];
	int len;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%s", &str);
			len = strlen(str);
			for (int i = 0; i < len; i++) {
				if (str[i]+a[i] < 123)
					str[i] = str[i]+a[i];
				else
					str[i] = str[i]+a[i]-26;
			}
			printf("%s\n", str);
		}
		break;
	}

	return 0;
}
