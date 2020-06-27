#include <stdio.h>
#include <string.h>

int main()
{
	char *str0="1";
	char str1[4]="";
	char str2[4]="abc";
	char str3[4]="abcd";
	char str4[4]="abcdef";

	printf("str0=%s, strlen(str0)=%ld, sizeof(str0)=%ld\n", str0, strlen(str0), sizeof(str0));
	printf("str1=%s, strlen(str1)=%ld, sizeof(str1)=%ld\n", str1, strlen(str1), sizeof(str1));
	printf("str2=%s, strlen(str2)=%ld, sizeof(str2)=%ld\n", str2, strlen(str2), sizeof(str2));
	printf("str3=%s, strlen(str3)=%ld, sizeof(str3)=%ld\n", str3, strlen(str3), sizeof(str3));
	printf("str4=%s, strlen(str4)=%ld, sizeof(str4)=%ld\n", str4, strlen(str4), sizeof(str4));

	return 0;
}
