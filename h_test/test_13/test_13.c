#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	scanf("%s", &str);

	int len = strlen(str);
	int temp;

	for (int i = 0; i < len; i++) {
		if (str[i] <= '9') {		// 如果不只个位数，要再加判断条件
			temp = str[i]-48;
			for (int j = 0; j < temp-1; j++)
				printf("%c", str[i+1]);
		}else
			printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}
