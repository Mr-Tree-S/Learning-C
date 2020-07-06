#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
}Node;

typedef struct linklist {
	Node *head;
//	Node *tail;
}List;

void create_list(List *pList, int data)
{
//	add to linked-list
	Node *p = (Node*)malloc(sizeof(Node));
	p->val = data;
	p->next = NULL;
//	find the last
	Node *last = pList->head;
	if (last) {
		while(last->next){
			last = last->next;
		}
		last->next = p;		// add tail node
	}else{
		pList->head = p;	// head node
	}
}

void printf_list(List *pList)
{
	Node *p = pList->head;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

void free_list(List *pList)
{
	Node *p = pList->head;
	Node *temp;
	while (p) {
		temp = p;
		p = p->next;
		free(temp);
	}
	pList->head = NULL;
}

void del_node(List *pList, int number)
{
	Node *pre = pList->head;
	Node *temp;
	for (int i = 1; i < number-1; i++) {
		pre = pre->next;
	}

	if (pre->next) {
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
	
	if (pre->next) {
		pre->next->val = data;
	} else {
		printf("node not exist!!!");
	}
}


int main(int argc, char const *argv[])
{
	List L;
	L.head=NULL;
	int n;

	do {
		scanf("%d", &n);
		if (n != 0) {
			create_list(&L, n);
		}
	} while (n != 0);
	
	ins_node(&L, 2, 2);
	del_node(&L, 3);
	change_node(&L, 3, 3);

	printf_list(&L);

	free_list(&L);
	printf("after free\n");
	printf_list(&L);

	return 0;
}
