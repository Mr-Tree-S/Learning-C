#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define SLEN 20
typedef struct item {
	char petname[SLEN];
	char petkind[SLEN];
}Item;

typedef struct trnode {
	Itrm item;
	struct trnode *left;
	struct trnode *right;
}Trnode;

typedef struct tree {
	Trnode *root;
	int size;
}Tree;

typedef struct pair {
	Trnode *parent;
	Trnode *child;
}Pair;


bool AddItem(const Item *pi, Tree *ptree)
{
	Trnode *nex_node;
	if (TreeIsFull(ptree)) {
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	if (SeekItem(pi, ptree).child != NULL) {
		fprintf(stderr, "Attempted to add duplicate item\n");
		return false;
	}
	new_node = MakeNode(pi);
	if (new_node == NULL) {
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root == new_node;
	else
		AddNode(new_node, ptree->root);
	return true;
}

static Trnode *MakeNode(const Item *pi)
{
	Trnode *new_node;
	new_node = (Trnode*)malloc(sizeof(Trnode));
	if (new_node != NULL) {
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static void AddNode(Trnode *new_node, Trnode *root)
{
	if (ToLeft(&new_node->item, &root->item)) {
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	} else if (ToRight(&new_node->item, &root->item)) {
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	} else {
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item *i1, const Item *i2) {
	int comp1;
	if (comp1 = strcmp(i1->petname, i2->petkind) < 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item *i1, const Item *i2) {
	int comp1;
	if (comp1 = strcmp(i1->petname, i2->petkind) > 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
		return true;
	else
		return false;
}

static Pair SeekItem(const Item *pi, const Tree *ptree) {
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if (look.child == NULL)
		return look;
	while (look.child != NULL) {
		if (ToLeft(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->left;
		} else if (ToRight(pi, &(look.child->item))) {
			look.parent = look.child;
			look.child = look.child->right;
		} else
			break;
	}
	return look;
}

bool InTree(const Item *pi, const Tree *ptree) {
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

static void DeleteNode(Trnode **p)
{
	Trnode *temp;
	if ((*ptr)->left == NULL) {
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	} else if

}

