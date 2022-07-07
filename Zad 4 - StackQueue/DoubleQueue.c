#include "queue.h"
#include "doublequeue.h"

#include <stdio.h>

void initdq(DoubleQueue *Q){
	
	Q -> length = 0;
	Q -> head = 0;
	Q -> tail = 0;
	
	return;
	
}

void enqueued(DoubleQueue *Q, int k){
	
	if(Q -> length < ROZMIAR_KOLEJKI*2){
	
		if(Q -> tail == 2*ROZMIAR_KOLEJKI) Q -> tail = 0;
		
		Q -> data[Q -> tail] = k;
		
		Q -> tail++;
		
		Q -> length++;
	
	}
	else printf("przepelnienie\n");

	return;

}

void writedq(DoubleQueue Q){
	
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

void MergeQueue(Queue *A, Queue *B, DoubleQueue *C){
	
	int czyAmaElementy = 1, czyBmaElementy = 1;
	int temp;
	
	while(czyAmaElementy == 1 || czyBmaElementy == 1){

		temp = dequeue(A);
		if(temp == -1) czyAmaElementy = 0;
		if(czyAmaElementy == 1) enqueued(C, temp);
		
		temp = dequeue(B);
		if(temp == -1) czyBmaElementy = 0;
		if(czyBmaElementy == 1) enqueued(C, temp);
		
	}
	
}

