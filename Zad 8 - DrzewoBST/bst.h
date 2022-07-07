#ifndef BST
#define BST

#include "tree.h"

struct Node *treeSearchRecursive(struct Tree T, int key);
struct Node *treeSearchIterative(struct Tree T, int key);
struct Node *treeSuccessor(struct Node *x);
void treeInsert(struct Tree *T, int k);
void treeDelete(struct Tree *T, int k);
struct Node *treeMinimum(struct Tree T);
struct Node *treeMaximum(struct Tree x);
struct Node *treePredecessor(struct Node *x);
struct Node *smallestSuccessor(struct Tree T);
void write(struct Node a);

#endif

