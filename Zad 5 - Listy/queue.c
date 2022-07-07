#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

void initq(Queue *Q){
	
	Q -> list = malloc(sizeof(Lista));
	init(Q -> list);
	
	return;
	
}

char *queueempty(Queue Q){
	
	if(Q.list -> head == NULL) return "true";
	else return "false";
	
}

void enqueue(Queue *Q, int k){
	
	insert(Q -> list, k);

	return;

}

char *dequeue(Queue *Q){
	
	Element *x;
	char *a = malloc(sizeof(char) * 100);
	
	if(Q -> list -> head == 0) return "niedomiar";
	else {
		
		x = Q -> list -> tail;
		itoa(x -> key, a, 10);
		Q -> list -> tail = x -> prev;
		
		if(x -> prev != NULL) {
			
			x -> prev -> next = NULL;
			
		}
		else {
			
			Q -> list -> head = NULL;
			
		}
		
		free(x);
		
		return a;
		
	}
	
}

void writeq(Queue Q){
	
	Element *x = Q.list -> tail;
	
	while(x != NULL){
		
		printf("%d ", x -> key);
		x = x -> prev;
		
	}
	
	printf("\n");
	
	return;
	
}

void clearq(Queue *Q){
	
	clear(Q -> list);
	
	return;
	
}

