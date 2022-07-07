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
void writeTree(struct Tree T);
void clear(struct Tree *T);
struct Node *newNode(int key, struct Node *p, bool isLeftChild);

#endif

