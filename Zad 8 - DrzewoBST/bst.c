#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "bst.h"

struct Node *searchRecursive(struct Node *k, int key) {
	
	if(k -> key == key) return k;
	else if(key < k -> key && k -> left != NULL) return searchRecursive(k -> left, key);
	else if(key > k -> key && k -> right != NULL) return searchRecursive(k -> right, key);
	else return NULL;
	
}

struct Node *treeSearchRecursive(struct Tree T, int key) {
	
	if(T.root != NULL) return searchRecursive(T.root, key);
	else return NULL;
	
}

struct Node *treeSearchIterative(struct Tree T, int key) {
	
	struct Node *node;
	
	if(T.root == NULL) return NULL;
	
	node = T.root;
	
	while(true){
		
		if(node -> key == key || node == NULL) break;
		else if(key > node -> key) node = node -> right;
		else node = node -> left;
		
	}
	
	return node;
	
}

void treeInsert(struct Tree *T, int k) {
	
	struct Node *p = T -> root, *pop = NULL;
	
	while(p != NULL){
		
		pop = p;
		
		if(k >= p -> key) p = p -> right;
		else p = p -> left;
		
	}
	
	if(pop != NULL){
		
		if(k >= pop -> key) newNode(k, pop, 1);
		else newNode(k, pop, 0);
		
	}
	else T -> root = newNode(k, NULL, -1);
	
	return;
	
}

void write(struct Node a) {
	
	printf("%i\n", a.key);
	
	return;
	
}

struct Node *min(struct Node *node) {
	
	struct Node *temp = node, *ret = temp;
	
	while(ret != NULL){
		
		temp = ret;
		ret = ret -> left;
		
	}
	
	return temp;
	
}

struct Node *treeMinimum(struct Tree T) {
	
	return min(T.root);
	
}

struct Node *max(struct Node *node) {
	
	struct Node *temp = node, *ret = temp;
	
	while(ret != NULL){
		
		temp = ret;
		ret = ret -> right;
		
	}
	
	return temp;
	
}

struct Node *treeMaximum(struct Tree T) {
	
	return max(T.root);
	
}

struct Node *treeSuccessor(struct Node *x) {
	
	if(x == NULL) return NULL;
	else if(x -> right != NULL) return min(x -> right);
	else if(x -> p != NULL){
		
		while(x != x -> p -> left && x != NULL){
			
			x = x -> p;
			
		}
	
		return x -> p;
		
	}
	else return NULL;
	
}

struct Node *treePredecessor(struct Node *x) {
	
	if(x == NULL) return NULL;
	else if(x -> left != NULL) return max(x -> left);
	else if(x -> p != NULL){
		
		while(x != x -> p -> right && x != NULL){
			
			x = x -> p;
			
		}
	
		return x -> p;
		
	}
	else return NULL;
	
}

struct Node *smallestSuccessor(struct Tree T) {
	
	return treeSuccessor(treeMinimum(T));
	
}

struct Node *deleteNode(struct Node *root, int k) {
	
	struct Node *temp;
	
	if(root == NULL) return root;
	
	if(k < root -> key) root -> left = deleteNode(root -> left, k);
	else if(k > root -> key) root -> right = deleteNode(root -> right, k);
	else {
		
		if(root -> left == NULL){
			
			temp = root -> right;
			free(root);
			return temp;
			
		}
		
		if(root -> right == NULL){
			
			temp = root -> left;
			free(root);
			return temp;
			
		}
		
		temp = min(root -> right);
		root -> key = temp -> key;
		root -> right = deleteNode(root -> right, temp -> key);
		
	}
	
	return root;
	
}

void treeDelete(struct Tree *T, int k) {
	
	struct Node *do_usuniecia = treeSearchIterative(*T, k);
	
	if(T -> root == do_usuniecia){
		
		T -> root = NULL;
		free(do_usuniecia);
		
	}
	else deleteNode(T -> root, k);
	
	return;
	
}

