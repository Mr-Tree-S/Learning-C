#include <stdio.h>
#include <string.h>

int main()
{
	char str[60];
	scanf("%s", &str);
	
	int len = strlen(str);
	
	int a[5] = {0};
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ',') {
			j = 0;
			continue;
		}else if (str[i] == '1') {
			a[j]++;
			j++;
		}else if (str[i] == '0')
			j++;
	}

	int temp = a[0];
	for (int i = 0; i < 5; i++) {
		if (a[i] < temp)
			temp = a[i];
	}
	printf("%d\n", temp);

	return 0;
}
