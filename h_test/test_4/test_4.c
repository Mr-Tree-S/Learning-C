#include <stdio.h>
#include <string.h>

#define M 25
#define N 7


void swap(char *a, char *b) {
	char tmp[N];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}

void sort(char num[M][N], int n)  //修改过后的冒泡排序
{
	char ab[13];
	char ba[13];
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++) {
			strcpy(ab, num[j]);
			strcat(ab, num[j+1]);
			strcpy(ba, num[j+1]);
			strcat(ba, num[j]);
			if (strcmp(ab, ba) < 0)
				swap(num[j], num[j+1]);
			}
	}
}

int main()
{
	char str[M][N] = {0};
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	sort(str, n);
	for (int i = 0; i < n; i++) {
		printf("%s", str[i]);
	}

	return 0;
}
