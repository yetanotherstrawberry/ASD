#ifndef STACK
#define STACK

#include "lista.h"

#include <stdbool.h>

struct Stack {
	
	Lista *list;
	
} Stack;

void inits(struct Stack *S);
int stackempty(struct Stack S);
void push(struct Stack *S, struct Node *k);
struct Node *pop(struct Stack *S);

#endif

