#include <stdio.h>

#include "stackbyqueue.h"

void initsbq(StackByQueue *S){
	
	initq(&(S -> jeden));
	initq(&(S -> dwa));
	
	return;
	
}

int sbqempty(StackByQueue S){
	
	if(queueempty(S.jeden)) return 1;
	else return 0;
	
}

void sbqpush(StackByQueue *S, int k){

	enqueue(&(S -> jeden), k);

	return;
	
}

int sbqpop(StackByQueue *S){
	
	int ile_elementow = 0, i = 0;
	int ostatni_element;
	
	while(!queueempty(S -> jeden)){
	
		ostatni_element = dequeue(&(S -> jeden));
		ile_elementow++;
		enqueue(&(S -> dwa), ostatni_element);
		i = -1;
	
	}
	
	if (i != -1) return -1;
	
	for(i = 0; i < ile_elementow - 1; i++) enqueue(&(S -> jeden), dequeue(&(S -> dwa)));
	
	dequeue(&(S -> dwa));
	
	return ostatni_element;
	
}

void writesbq(StackByQueue S){
	
	int ostatni_element;
	
	while(!queueempty(S.jeden)){
	
		ostatni_element = dequeue(&(S.jeden));
		printf("%i ", ostatni_element);
		enqueue(&(S.dwa), ostatni_element);
	
	}
	
	while(!queueempty(S.dwa)){
	
		ostatni_element = dequeue(&(S.dwa));
		enqueue(&(S.jeden), ostatni_element);
	
	}
	
	printf("\n");
	
	return;
		
}

void writesbqempty(int sbqempty){
	
	if(sbqempty == 1) printf("true\n");
	else printf("false\n");
	
	return;
	
}

void printsbq(int element){
	
	if(element == -1) printf("niedomiar\n");
	else printf("%i\n", element);
	
	return;
	
}

