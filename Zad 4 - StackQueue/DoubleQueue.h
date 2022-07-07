#ifndef DOUBLEQUEUE
#define DOUBLEQUEUE

#include "queue.h"

typedef struct {
	
	int data[2*ROZMIAR_KOLEJKI];
	int length;
	int head;
	int tail;
	
} DoubleQueue;

void initdq(DoubleQueue *Q);
void enqueued(DoubleQueue *Q, int k);
void MergeQueue(Queue *A, Queue *B, DoubleQueue *C);
void writedq(DoubleQueue S);

#endif

