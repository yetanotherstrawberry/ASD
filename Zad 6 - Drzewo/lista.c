#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

void initl(Lista *L){
	
	L -> head = NULL;
	L -> tail = NULL;
	
	return;
	
}

void insert(Lista *L, struct Node *k){
	
	Element *x = malloc(sizeof(Element));
	x -> key = k;
	x -> prev = NULL;
	
	if(L -> head == NULL){

		x -> next = NULL;
		L -> head = x;
		L -> tail = x;
		
	}
	else {
		
		x -> next = L -> head;
		L -> head -> prev = x;
		L -> head = x;
		
	}
	
	return;
	
}

