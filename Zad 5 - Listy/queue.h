#ifndef QUEUE
#define QUEUE

#include "lista.h"

#include <stdbool.h>

typedef struct Queue {
	
	Lista *list;
	
} Queue;

void initq(Queue *Q);
char *queueempty(Queue Q);
void enqueue(Queue *Q, int k);
char *dequeue(Queue *Q);
void writeq(Queue Q);
void clearq(Queue *Q);

#endif

