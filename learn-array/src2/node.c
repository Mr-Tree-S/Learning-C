#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct _node{
	int value;
	struct _node *next;
}Node;
*/

typedef struct _list{
	Node *head;
//	Node *tail;
}List;

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

	return 0;
}

void printf_node(List *pList)
{
	Node *p;
	for(p=pList->head; p; p=p->next){
		printf("%d ", p->value);
	}
	printf("\n");

	return 0;
}

int main(int argc, char const *argv[])
{
	int number;
	List list;
	list.head=NULL;
	do{
		scanf("%d",&number);
		if(number != -1){
			head=add(&list, number);
		}
	}while(number != -1);
	printf_node(&list);
	
	Node *p;
	for(p=list.head; p; p=p->next){
		if(p->value=number){
			printf("OhYeah! Find it!\n");
			break;
		}else{
			printf("404 NOT FOUND");
			break;
		}
	}

	for(p=head; p; p=q){
		q=p->next;
		free(p);
	}

	return 0;
}
