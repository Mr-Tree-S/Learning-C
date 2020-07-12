#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	scanf("%[^\n]", &str);

	char *p;
	p = strtok(str, " ");

	double sum = 0;
	double n = 0;
	while (p) {
		sum = sum+strlen(p);
		n++;
		p = strtok(NULL, " ");
	}

	double d = sum/n;
	printf("%.2lf\n", d);

	return 0;
}
