#ifndef TREE
#define TREE

#include <stdbool.h>

struct Node {
	
	int key;
	struct Node *p;
	struct Node *left;
	struct Node *right;
	
} Node;

struct Tree {
	
	struct Node *root;
	
};

void init(struct Tree *T);
void maketree(struct Tree *T, int n);
void printtree(struct Tree T);
void preordertree(struct Tree T);
void inordertree(struct Tree T);
void postordertree(struct Tree T);
void clear(struct Tree *T);
int leafcount(struct Tree T);
void make_tree_rek(struct Tree *T, int n);

#endif

