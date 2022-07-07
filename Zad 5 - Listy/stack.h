#ifndef STACK
#define STACK

#include "lista.h"

#include <stdbool.h>

typedef struct Stack {
	
	Lista *list;
	
} Stack;

void inits(Stack *S);
char *stackempty(Stack S);
void push(Stack *S, int k);
char *pop(Stack *S);
void writes(Stack S);
void clears(Stack *S);

#endif

