#include "node.h"
#include <stdio.h>
#include <stdlib.h>


void add(List *pList, int number)
{
	// add to linked-list
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	// find the last
	Node *last=pList->head;
	if(last){
		while(last->next){
			last=last->next;
		}
		// attach
		last->next=p;
	}else{
		pList->head=p;
	}
}

void printf_node(List *pList)
{
	Node *p;
	for(p=pList->head; p; p=p->next){
		printf("%d ", p->value);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int number;
	List list;
	list.head=NULL;
	do {
		scanf("%d", &number);
		if (number != -1) {
			add(&list, number);
		}
	} while (number != -1);
	printf_node(&list);

/*
	Node *p;
	for (p=list.head; p; p=p->next) {
		if (p->value = number) {
			printf("OhYeah! Find it!\n");
			break;
		} else {
			printf("404 NOT FOUND");
			break;
		}
	}
*/

	return 0;
}
