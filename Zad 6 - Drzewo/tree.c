#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"
#include "tree.h"

void init(struct Tree *T){
	
	T -> root = NULL;
	
	return;
	
}

struct Node *newNode(int key, struct Node *p, bool isLeftChild){
	
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

void inordertree(struct Tree T){
	
	struct Node *aktualny = NULL;
	struct Stack stosik;
	
	if(T.root != NULL) aktualny = T.root;
	inits(&stosik);
	
	while(true){
		
		if(aktualny != NULL) {
			
			push(&stosik, aktualny);
			aktualny = aktualny -> left;
			
		}
		else {
			
			aktualny = pop(&stosik);
			printf("%i ", aktualny -> key);
			aktualny = aktualny -> right;
			
		}
		
		if(aktualny == NULL && strcmp(stackempty(stosik), "true") == 0) break;
		
	}
	
	printf("\n");
	
	return;
	
}

void preordertree(struct Tree T){
	
	struct Node *aktualny = NULL;
	struct Stack stosik;
	
	if(T.root != NULL) aktualny = T.root;
	inits(&stosik);
	
	while(true){
		
		if(aktualny != NULL) {
			
			push(&stosik, aktualny);
			printf("%i ", aktualny -> key);
			aktualny = aktualny -> left;
			
		}
		else {
			
			aktualny = pop(&stosik);
			aktualny = aktualny -> right;
			
		}
		
		if(aktualny == NULL && strcmp(stackempty(stosik), "true") == 0) break;
		
	}
	
	printf("\n");
	
	return;
	
}

void postordertree(struct Tree T){
	
	struct Node *aktualny = NULL;
	struct Stack stosik_jeden;
	struct Stack stosik_dwa;
	
	inits(&stosik_jeden);
	inits(&stosik_dwa);
	if(T.root != NULL) push(&stosik_jeden, T.root);
	
	while(strcmp(stackempty(stosik_jeden), "false") == 0){
		
		aktualny = pop(&stosik_jeden);
		push(&stosik_dwa, aktualny);
		if(aktualny->left != NULL) push(&stosik_jeden, aktualny->left);
		if(aktualny->right != NULL) push(&stosik_jeden, aktualny->right);
		
	}
	
	while(strcmp(stackempty(stosik_dwa), "false") == 0) printf("%i ", pop(&stosik_dwa) -> key);
	
	printf("\n");
	
	return;
	
}

int leafcount(struct Tree T){
	
	int ile = 0;
	struct Node *aktualny = NULL;
	struct Stack stosik;
	
	if(T.root != NULL) aktualny = T.root;
	inits(&stosik);
	
	while(true){
		
		if(aktualny != NULL) {
			
			if(aktualny -> right == NULL && aktualny -> left == NULL) ile++;
			push(&stosik, aktualny);
			aktualny = aktualny -> left;
			
		}
		else {
			
			aktualny = pop(&stosik);
			aktualny = aktualny -> right;
			
		}
		
		if(aktualny == NULL && strcmp(stackempty(stosik), "true") == 0) break;
		
	}
	
	return ile;
	
}

struct Node *randomWalkTree(struct Node *N){
	
	struct Node *x = N;
	struct Node *y = NULL;
	
	while(x != NULL){
		
		y = x;
		
		if((rand() % 2) == 0) x = x -> left;
		else x = x -> right;
		
	}
	
	return y;
	
}

void maketree(struct Tree *T, int n){
	
	struct Node *aktualny;
	
	srand((unsigned)time(NULL));
	
	if(T == NULL) {
		
		printf("Nie ma zadnego drzewa!\n");
		return;
		
	}
	
	if(T -> root == NULL) T -> root = newNode(rand() % 101, NULL, 0);
	
	while(--n > 0){
		
		aktualny = randomWalkTree(T -> root);
		
		if(aktualny -> left == NULL && aktualny -> right == NULL) newNode(rand() % 101, aktualny, rand() % 2);
		else if(aktualny -> left == NULL) newNode(rand() % 101, aktualny, 0);
		else newNode(rand() % 101, aktualny, 1);
		
	} 

	return;
	
}

void clear(struct Tree *T){
	
	struct Node *aktualny = NULL;
	struct Stack stosik_jeden;
	struct Stack stosik_dwa;
	
	inits(&stosik_jeden);
	inits(&stosik_dwa);
	if(T -> root != NULL) push(&stosik_jeden, T -> root);
	
	while(strcmp(stackempty(stosik_jeden), "false") == 0){
		
		aktualny = pop(&stosik_jeden);
		push(&stosik_dwa, aktualny);
		if(aktualny->left != NULL) push(&stosik_jeden, aktualny->left);
		if(aktualny->right != NULL) push(&stosik_jeden, aktualny->right);
		
	}
	
	while(strcmp(stackempty(stosik_dwa), "false") == 0) free(pop(&stosik_dwa));

	T -> root = NULL;
	
	return;
	
}

void pokaInorder(struct Node *nodzik, int wciecie) 
{
	
	int i = 0;
	if (nodzik == NULL) return;
	pokaInorder(nodzik -> left, wciecie + 1);
	for(; i < wciecie; i++) printf("\t");
	printf("%i \n", nodzik -> key);
	pokaInorder(nodzik -> right, wciecie + 1);
	
	return;
	
}

void printtree(struct Tree T){
	
	pokaInorder(T.root, 0);
	
	return;
	
}

void make_tree_rek(struct Tree *T, int n){
	
	struct Node *jakis_nodzik = randomWalkTree(T -> root);
	
	if(jakis_nodzik == NULL) T -> root = newNode(rand() % 101, jakis_nodzik, rand() % 2);
	else if(jakis_nodzik -> left == NULL && jakis_nodzik  -> right == NULL) newNode(rand() % 101, jakis_nodzik, rand() % 2);
	else if(jakis_nodzik -> left == NULL) newNode(rand() % 101, jakis_nodzik, 0);
	else newNode(rand() % 101, jakis_nodzik, 1);
	
	if(n > 1) make_tree_rek(T, n - 1);
	
	return;
	
}

