#include "stack.h"
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

void inits(Stack *S){
	
	S -> list = malloc(sizeof(Lista));
	init(S -> list);
	
	return;
	
}

char *stackempty(Stack S){
	
	if(S.list -> head == NULL) return "true";
	else return "false";
	
}

void push(Stack *S, int k){
	
	insert(S -> list, k);

	return;

}

char *pop(Stack *S){
	
	Element *x;
	char *a = malloc(sizeof(char) * 100);
	
	if(S -> list -> head == NULL) return "niedomiar";
	else {
		
		x = S -> list -> head;
		itoa(x -> key, a, 10);
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

void writes(Stack S){
	
	Element *x = S.list -> tail;
	
	while(x != NULL){
		
		printf("%d ", x -> key);
		x = x -> prev;
		
	}
	
	printf("\n");
	
	return;
	
}

void clears(Stack *S){
	
	clear(S -> list);
	
	return;
	
}

