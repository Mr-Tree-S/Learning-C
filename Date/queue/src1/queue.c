#include <stdio.h>
#include <stdlib.h>


typedef struct queuelist {
	int *list;
	int front;
	int rear;
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
	pList->front = 0;
	pList->rear = 0;
	pList->max = max;
	return pList;
}

void printf_list(List *pList)
{
	for (int i = 0; i <= pList->rear; i++)
		printf("第%d项:%d\n", i, pList->list[i]);
}
int in_list(List *pList, int data)
{
	if (pList->rear == pList->front && pList->list[pList->rear] == 0) {
		pList->list[pList->rear] = data;
	} else {
	pList->rear = (pList->rear+1)%pList->max;
	pList->list[pList->rear] = data;
	}
	return pList->rear;
}

int out_list(List *pList)
{
	int temp = pList->list[pList->front];
	pList->list[pList->front] = 0;
	pList->front = (pList->front+1)%pList->max;
	return temp;
}

int main()
{
	int m =20;
	List *L = create_list(m);

	for(int i = 0; i < 10; i++) {
		in_list(L, i+1);
	}
	
	printf_list(L);

	return 0;
}
