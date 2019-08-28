#include <stdio.h>
#include <string.h>

int main()
{
	char *str1="1";
	char str2[10]="22";
	char str3[5]="12345";

	printf("strlen(str1)=%d, sizeof(str1)=%d\n", strlen(str1), sizeof(str1));
	printf("strlen(str2)=%d, sizeof(str2)=%d\n", strlen(str2), sizeof(str2));
	printf("strlen(str3)=%d, sizeof(str3)=%d\n", strlen(str3), sizeof(str3));

	return 0;
}
