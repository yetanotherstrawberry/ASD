#include "stack.h"

#include <stdio.h>

void inits(Stack *S){
	
	S -> top = 0;
	
}

int stackempty(Stack S){
	
	if(S.top == 0) return 1;
	else return 0;
	
}

void push(Stack *S, int k){
	
	if(S -> top < ROZMIAR_STOSU) S -> data[S -> top++] = k;
	else printf("przepelnienie\n");

	return;

}

int pop(Stack *S){
	
	if(S -> top == 0) return -1;
	else {
		
		S -> top--;
		return S -> data[S -> top];
		
	}
	
}

void writes(Stack S){
	
	int i;
	for(i = 0; i < S.top; i++) printf("%i ", S.data[i]);
	printf("\n");
	
}

void stackemptywrite(int stackempty){
	
	if(stackempty == 1) printf("true\n");
	else printf("false\n");
	
	return;
	
}

void prints(int element){
	
	if(element == -1) printf("niedomiar\n");
	else printf("%i\n", element);
	
	return;
	
}

