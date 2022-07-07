#include "queue.h"

#include <stdio.h>

void initq(Queue *Q){
	
	Q -> length = 0;
	Q -> head = 0;
	Q -> tail = 0;
	
	return;
	
}

int queueempty(Queue Q){
	
	if(Q.length == 0) return 1;
	else return 0;
	
}

void enqueue(Queue *Q, int k){
	
	if(Q -> length < ROZMIAR_KOLEJKI){
	
		if(Q -> tail == ROZMIAR_KOLEJKI) Q -> tail = 0;
		
		Q -> data[Q -> tail] = k;
		
		Q -> tail++;
		
		Q -> length++;
	
	}
	else printf("przepelnienie\n");

	return;

}

int dequeue(Queue *Q){
	
	int ret;
	
	if(Q -> length == 0) return -1;
	
	Q -> length--;
	
	ret = Q -> data[Q -> head];
	
	if(Q -> head == ROZMIAR_KOLEJKI - 1) Q -> head = 0;
	else Q -> head++;
	
	return ret;
	
}

void writeq(Queue Q){
	
	int i, miejsce;
	if(Q.tail > Q.head) for(i = Q.head; i < Q.tail; i++) printf("%i ", Q.data[i]);
	else {
		
		miejsce = Q.head;
		i = 1;
		while(i <= Q.length){
			if(miejsce == Q.length) miejsce = 0;
			printf("%i ", Q.data[miejsce]);
			i++;
			miejsce++;
		}
		
	}
	printf("\n");
	
}

int rozmiar(Queue Q){
	
	int roz = 0;
	Queue S;
	initq(&S);
	
	while(!queueempty(Q)) {
		
		roz++;
		enqueue(&S, dequeue(&Q));
		
	}
	
	while(!queueempty(S)) enqueue(&Q, dequeue(&S));
	
	return roz;
	
}

void queueemptywrite(int queueempty){

	if(queueempty == 1) printf("true\n");
	else printf("false\n");
	
	return;
	
}

void printq(int element){
	
	if(element == -1) printf("niedomiar\n");
	else printf("%i\n", element);
	
	return;
	
}

