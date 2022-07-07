#include "stack.h"
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

void inits(struct Stack *S){
	
	S -> list = malloc(sizeof(Lista));
	initl(S -> list);
	
	return;
	
}

int stackempty(struct Stack S){
	
	if(S.list -> head == NULL) return 1;
	else return 0;
	
}

void push(struct Stack *S, struct Node *k){
	
	insert(S -> list, k);

	return;

}

struct Node *pop(struct Stack *S){
	
	Element *x;
	struct Node *a;
	
	if(S -> list -> head == NULL) return NULL;
	else {
		
		x = S -> list -> head;
		a = x -> key;
		S -> list -> head = x -> next;
		
		if(x -> next != NULL) {
			
			x -> next -> prev = NULL;
			
		}
		else{
			
			S -> list -> tail = NULL;
		
		}
		
		free(x);
		
		return a;
		
	}
	
}

