#include <stdio.h>
#include <stdlib.h>


typedef struct stacklist {
	int *list;
	int top;
	int max;
}List;

List *create_list(int max)
{
	List *pList = (List*)malloc(sizeof(List));
	if (pList == NULL)
		return NULL;
	pList->list = (int*)malloc(sizeof(int)*max);
	if (pList->list == NULL)
		return NULL;
	pList->top = 0;
	pList->max = max;
	return pList;
}

void printf_list(List *pList)
{
	for (int i = 0; i < pList->top; i++)
		printf("第%d项:%d\n", i, pList->list[i]);
}

int push(List *pList, int data)
{
	if (pList->top == pList->max) {
		printf("栈已满\n");
		return -1;
	}
	pList->list[pList->top] = data;
	pList->top++;
	return pList->top;
}

int pop(List *pList)
{
	if (pList->top >= 0) {
		pList->top--;
		return pList->list[pList->top];
	}
	return -1;
}


int main()
{
	int m = 20;
	List *L = create_list(m);

	for(int i = 0; i < 10; i++) {
		int r = push(L, i);
		if (r == -1) {
			printf("栈已满\n");
			break;
		}
	}

	printf_list(L);

	return 0;
}
