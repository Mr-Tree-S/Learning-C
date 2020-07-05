/*
输入描述:
每组数据输入一个字符串，字符串最大长度为100，
且只包含字母，不可能为空串，区分大小写。
输出描述:
每组数据一行，按字符串原有的字符顺序，输出字符集合，
即重复出现并靠后的字母不输出。
*/

#include <stdio.h>


int main()
{
	char str[101];
	int a[256] = {0};
	
	scanf("%s", &str);
	for (int i = 0; str[i] != '\0'; i++) {
		a[str[i]]++;
		if (a[str[i]] == 1) {
			printf("%c", str[i]);
		}
	}
	printf("\n");
	
	return 0;
}
