#include "stack.h"
#include "doublestack.h"

#include <stdio.h>

void initds(DoubleStack *S){
	
	S -> top = 0;
	
}

void pushd(DoubleStack *S, int k){
	
	if(S -> top < ROZMIAR_STOSU*2) S -> data[S -> top++] = k;
	else printf("przepelnienie\n");

	return;

}

void MergeStack(Stack *A, Stack *B, DoubleStack *C){
	
	Stack tempA, tempB;
	int czyAmaElementy = 1, czyBmaElementy = 1;
	int temp;
	
	inits(&tempA);
	inits(&tempB);
	
	while(czyAmaElementy == 1){
	
		temp = pop(A);
		if(temp == -1) czyAmaElementy = 0;
		if(czyAmaElementy == 1) push(&tempA, temp);
	
	}
	
	while(czyBmaElementy == 1){
	
		temp = pop(B);
		if(temp == -1) czyBmaElementy = 0;
		if(czyBmaElementy == 1) push(&tempB, temp);
	
	}
	
	czyAmaElementy = 1;
	czyBmaElementy = 1;

	while(czyAmaElementy == 1 || czyBmaElementy == 1){

		temp = pop(&tempA);
		if(temp == -1) czyAmaElementy = 0;
		if(czyAmaElementy == 1) pushd(C, temp);
		
		temp = pop(&tempB);
		if(temp == -1) czyBmaElementy = 0;
		if(czyBmaElementy == 1) pushd(C, temp);
		
	}
	
}

void writeds(DoubleStack S){
	
	int i;
	for(i = 0; i < S.top; i++) printf("%i ", S.data[i]);
	printf("\n");
	
}

