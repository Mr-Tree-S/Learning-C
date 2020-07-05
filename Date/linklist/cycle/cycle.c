#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
}Node;

typedef struct list {
	Node *head;
//	Node *tail;
}List;

void create_node(List *pList, int data)
{
//	add to linked-list
	Node *p = (Node*)malloc(sizeof(Node));
	p->val = data;
	p->next = NULL;
//	find the last
	Node *last = pList->head;
	if (last) {
		while(last->next != pList->head){
			last = last->next;
		}
		last->next = p;		// add tail node
	}else{
		pList->head = p;	// head node
	}

	p->next = pList->head;		// add cyclic node
}

void del_node(List *pList, int number)
{
	Node *pre = pList->head;
	Node *temp;
	for (int i = 1; i < number-1; i++) {
		pre = pre->next;
	}

	if (pre->next != pList->head) {
		temp = pre->next;
		pre->next = pre->next->next;
		free(temp);
	} else {
		printf("node not exist!!!");
	}
}

void ins_node(List *pList, int number, int data)
{
	Node *pre = pList->head;
	Node *p = (Node*)malloc(sizeof(Node));
	p->val = data;
	p->next = NULL;

	for (int i = 1; i < number-1; i++) {
		pre = pre->next;
	}

	p->next = pre->next;
	pre->next = p;
}

void change_node(List *pList, int number, int data)
{
	Node *pre = pList->head;
	for (int i = 1; i < number-1; i++) {
		pre =pre->next;
	}
	
	if (pre->next != pList->head) {
		pre->next->val = data;
	} else {
		printf("node not exist!!!");
	}
}

void free_node(List *pList)
{
	Node *pre = pList->head;
	Node *temp;
	while (pre) {
		temp = pre;
		pre = pre->next;
		free(temp);
	}
	pList->head = NULL;
}

void printf_node(List *pList)
{
	Node *p = pList->head;
	while (p->next != pList->head) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("%d ", p->val);
	printf("\n");
}


int main(int argc, char const *argv[])
{
	List L;
	L.head=NULL;
	int n;

	do {
		scanf("%d", &n);
		if (n != 0) {
			create_node(&L, n);
		}
	} while (n != 0);
	
	ins_node(&L, 2, 2);
	del_node(&L, 3);
	change_node(&L, 3, 3);

	printf_node(&L);

//	free_node(&L);
//	printf("after free\n");
//	printf_node(&L);

	return 0;
}
