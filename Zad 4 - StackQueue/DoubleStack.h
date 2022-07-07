#ifndef DOUBLESTACK
#define DOUBLESTACK

#include "stack.h"

typedef struct {
	
	int data[ROZMIAR_STOSU*2];
	int top;
	
} DoubleStack;

void initds(DoubleStack *S);
void pushd(DoubleStack *S, int k);
void MergeStack(Stack *A, Stack *B, DoubleStack *C);
void writeds(DoubleStack S);

#endif

