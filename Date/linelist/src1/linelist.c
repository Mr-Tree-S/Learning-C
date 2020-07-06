#include <stdio.h>
#include <stdlib.h>


typedef struct linelist{
	int *list;
	int len;
	int MAXLEN;
}List;

List *create_list(int MAXLEN)
{
	List *pList = (List*)malloc(sizeof(List));
	if (pList != NULL) {
		pList->list = (int*)malloc(sizeof(int)*MAXLEN);
		if (pList->list == NULL)
			return NULL;
		pList->len = 0;
		pList->MAXLEN = MAXLEN;
	}
	return pList;
}

void printf_list(List *pList)
{
	for (int i = 0; i < pList->len; i++)
		printf("第%d项:%d\n", i, pList->list[i]);
}

void free_list(List *pList)
{
	free(pList->list);
}

int ins_node(List *pList, int number, int data)
{
	int n = number;
	if (n < 0 || n > pList->len || pList->len == pList->MAXLEN)
		return -1;
	for (int i = pList->len; i > n; i--)
		pList->list[i] = pList->list[i-1];
	pList->list[n] = data;
	pList->len++;
	return pList->len;
}

int del_node(List *pList, int number)
{
	int n = number;
	if (n < 0 || n > pList->len)
		return -1;
	for (int i = n; i < pList->len; i++) {
		pList->list[i] = pList->list[i+1];
	}
	pList->len--;
	return pList->len;
}

int find_node(List *pList, int data)
{
	for (int i = 0; i < pList->len; i++) {
		if (pList->list[i] == data) {
			printf("要找的元素为第%d项\n", i);
			return i;
		}
	}
	printf("404 NOT FOUND\n");
	return -1;
}

int main()
{
	List *L = create_list(20);

	for (int i = 0; i<10; i++) {
		ins_node(L, i, i);
	}
	
	ins_node(L, 1, 110);
	del_node(L, 1);
	printf_list(L);

	find_node(L, 1);
	find_node(L, 11);

	free_list(L);

	return 0;
}
