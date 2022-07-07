#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"
#include "tree.h"

void init(struct Tree *T) {
	
	T -> root = NULL;
	
	return;
	
}

struct Node *newNode(int key, struct Node *p, bool isLeftChild) {
	
	struct Node *node = malloc(sizeof(struct Node));
	
	node -> key = key;
	node -> p = p;
	node -> left = NULL;
	node -> right = NULL;
	
	if(p != NULL){
		
		if(isLeftChild == 0 && p -> left == NULL) p -> left = node;
		else if(isLeftChild == 1 && p -> right == NULL) p -> right = node;
		else {
			
			printf("Nie mozna dodac nowego liscia!\n");
			free(node);
			return NULL;
			
		}
		
	}
	
	return node;
	
}

void clear(struct Tree *T) {
	
	struct Node *aktualny = NULL;
	struct Stack stosik_jeden;
	struct Stack stosik_dwa;
	
	inits(&stosik_jeden);
	inits(&stosik_dwa);
	if(T -> root != NULL) push(&stosik_jeden, T -> root);
	
	while(stackempty(stosik_jeden) == 0){
		
		aktualny = pop(&stosik_jeden);
		push(&stosik_dwa, aktualny);
		if(aktualny->left != NULL) push(&stosik_jeden, aktualny -> left);
		if(aktualny->right != NULL) push(&stosik_jeden, aktualny -> right);
		
	}
	
	while(stackempty(stosik_dwa) == 0) free(pop(&stosik_dwa));

	T -> root = NULL;
	
	return;
	
}

void pokaInorder(struct Node *nodzik, int wciecie) {
	
	int i = 0;
	if (nodzik == NULL) return;
	pokaInorder(nodzik -> right, wciecie + 1);
	for(; i < wciecie; i++) printf("\t");
	printf("%i \n", nodzik -> key);
	pokaInorder(nodzik -> left, wciecie + 1);
	
	return;
	
}

void writeTree(struct Tree T) {
	
	printf("\n");
	pokaInorder(T.root, 0);
	
	return;
	
}

