#include <stdio.h>
#include <stdlib.h>


typedef struct linelist {
	int *list;
	int len;
	int max;
}List;

List *create_list(int max)
{
	List *pList = (List*)malloc(sizeof(List));
	pList->list = (int*)malloc(sizeof(int)*max);
	pList->len = 0;
	pList->max = max;
	return pList;
}

int ins_node(List *pList, int number, int data)
{
	int n = number;
	for (int i = pList->len; i > n; i--)
		pList->list[i] = pList->list[i-1];
	pList->list[n] = data;
	pList->len++;
	return pList->len;
}

int del_node(List *pList, int number)
{
	int n = number;
	for (int i = n; i < pList->len; i++)
		pList->list[i] = pList->list[i+1];
	pList->len--;
	return pList->len;
}

int fac(int n)
{
	int sum = 1;
	for (int i = 1; i <= n; i++)
		sum *= i;
	return sum;
}

void printf_list(List *pList)
{
	for (int i = 0; i < pList->len; i++)
		printf("第%d项:%d\n", i, pList->list[i]);
}


int main()
{
	int n;
	int k;
	scanf("%d\n%d", &n, &k);

	List *L = create_list(n);
	for (int i = 0; i < n; i++)
		ins_node(L, i, i+1);

	int c;
	int y = -1;
	int out[n];
	int i = 0;
	while (y != 1) {
		c = k/fac(n-1-i);
		y = k%fac(n-1-i);
		if (y == 0)
			break;
		out[i] = L->list[c];
		k = y;
		del_node(L, c);
		i++;
	}

	if (y == 0) {
		out[i] = L->list[c-1];
		del_node(L, c-1);
		i++;
		for (int j = 0; j < L->len; j++) {
			out[i] = L->list[L->len-1-j];
			i++;
		}
	} else {
		for (int j = 0; j < L->len; j++) {
			out[i] = L->list[j];
			i++;
		}
	}

	for (int j = 0; j < n; j++)
		printf("%d", out[j]);

	printf("\n");

	return 0;
}
