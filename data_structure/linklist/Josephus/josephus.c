#include <stdio.h>

typedef struct node {
	int val;
	struct node *next;
}Node;

Node *create_list(int n)
{
	int i;
	Node a[n];
	for (i = 0; i < n-1; i++) {
		a[i].val = i;
		a[i].next = &a[i+1];
	}
	a[i].val = i;
	a[i].next = a;

	Node *p = a;
	return p;
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	Node *p;
	p = create_list(n);
	while (p != p->next) {
		p->next->next = p->next->next->next;
		p = p->next->next;
	}
	printf("%d\n", p->val);

	return 0;
}
