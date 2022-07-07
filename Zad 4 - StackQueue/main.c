#include <stdio.h>

#include "queue.h"
#include "stack.h"
#include "stackbyqueue.h"
#include "doublequeue.h"
#include "doublestack.h"

int main(void) {
	
	Queue Q, QDWA;
	Stack S, SDWA;
	StackByQueue SBQ;
	DoubleQueue DQ;
	DoubleStack DS;
	
	printf("===Stos===\n");
	inits(&S);
	push(&S, 1);
	push(&S, 2);
	writes(S);
	push(&S, 3);
	writes(S);
	stackemptywrite(stackempty(S));
	prints(pop(&S));
	prints(pop(&S));
	writes(S);
	prints(pop(&S));
	prints(pop(&S));
	writes(S);
	stackemptywrite(stackempty(S));
	
	printf("===Kolejka===\n");
	initq(&Q);
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	writeq(Q);
	enqueue(&Q, 3);
	writeq(Q);
	queueemptywrite(queueempty(Q));
	printq(dequeue(&Q));
	printq(dequeue(&Q));
	writeq(Q);
	printq(dequeue(&Q));
	printq(dequeue(&Q));
	writeq(Q);
	queueemptywrite(queueempty(Q));
	
	printf("===Stos za pomoca dwoch kolejek===\n");
	initsbq(&SBQ);
	sbqpush(&SBQ, 1);
	sbqpush(&SBQ, 2);
	writesbq(SBQ);
	sbqpush(&SBQ, 3);
	writesbq(SBQ);
	writesbqempty(sbqempty(SBQ));
	printsbq(sbqpop(&SBQ));
	printsbq(sbqpop(&SBQ));
	writesbq(SBQ);
	printsbq(sbqpop(&SBQ));
	printsbq(sbqpop(&SBQ));
	writesbq(SBQ);
	writesbqempty(sbqempty(SBQ));
	
	printf("====Niepunktowane====\n");
	
	printf("===Scalanie dwoch stosow===\n");
	initds(&DS);
	inits(&SDWA);
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	writes(S);
	push(&SDWA, 10);
	push(&SDWA, 20);
	writes(SDWA);
	MergeStack(&S, &SDWA, &DS);
	writeds(DS);
	
	printf("===Scalanie dwoch kolejek===\n");
	initdq(&DQ);
	enqueue(&Q, 1);
	enqueue(&Q, 24);
	enqueue(&Q, 18);
	writeq(Q);
	initq(&QDWA);
	enqueue(&QDWA, 2);
	enqueue(&QDWA, 204);
	writeq(QDWA);
	MergeQueue(&Q, &QDWA, &DQ);
	writedq(DQ);

	printf("===Rozmiar kolejki===\n");
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	enqueue(&Q, 233);
	writeq(Q);
	printf("%i\n", rozmiar(Q));
	
	return 0;
	
}

