#ifndef STACKBYQUEUE
#define STACKBYQUEUE

#define ROZMIAR_STOSU 10

#include "queue.h"

typedef struct {
	
	Queue jeden;
	Queue dwa;
	
} StackByQueue;

void initsbq(StackByQueue *S);
int sbqempty(StackByQueue S);
void writesbqempty(int sbqempty);
void printsbq(int element);
void sbqpush(StackByQueue *S, int k);
int sbqpop(StackByQueue *S);
void writesbq(StackByQueue S);

#endif

