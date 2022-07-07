#ifndef STACK
#define STACK

#define ROZMIAR_STOSU 10

typedef struct {
	
	int data[ROZMIAR_STOSU];
	int top;
	
} Stack;

void inits(Stack *S);
int stackempty(Stack S);
void stackemptywrite(int stackempty);
void push(Stack *S, int k);
int pop(Stack *S);
void writes(Stack S);
void prints(int element);

#endif

