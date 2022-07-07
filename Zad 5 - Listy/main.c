#include <stdlib.h>
#include <stdio.h>

#include "lista.h"
#include "stack.h"
#include "queue.h"

int main(void){
	
	Lista *L = malloc(sizeof(Lista));
	Lista *Odwrocona = malloc(sizeof(Lista));
	Stack *Stos = malloc(sizeof(Stack));
	Queue *Kolejka = malloc(sizeof(Queue));
	
	printf("==Lista==\n");
	init(L);
	write(*L);
	insert(L, 1);
	insert(L, 2);
	write(*L);
	insert(L, 3);
	write_search(search(*L, 2));
	write_search(search(*L, 4));
	insertAfter(L, 4, 2);
	write(*L);
	listdelete(L, 2);
	write(*L);
	listdelete(L, 5);
	write(*L);
	insertBefore(L, 5, 3);
	write(*L);
	clear(L);
	write(*L);
	
	printf("\n==Stos lista==\n");
	inits(Stos);
	push(Stos, 1);
	push(Stos, 2);
	writes(*Stos);
	push(Stos, 3);
	writes(*Stos);
	printf("%s\n", stackempty(*Stos));
	printf("%s\n", pop(Stos));
	printf("%s\n", pop(Stos));
	writes(*Stos);
	printf("%s\n", pop(Stos));
	printf("%s\n", pop(Stos));
	writes(*Stos);
	printf("%s\n", stackempty(*Stos));
	clears(Stos);
	
	printf("\n==Kolejka lista==\n");
	initq(Kolejka);
	enqueue(Kolejka, 1);
	enqueue(Kolejka, 2);
	writeq(*Kolejka);
	enqueue(Kolejka, 3);
	writeq(*Kolejka);
	printf("%s\n", queueempty(*Kolejka));
	printf("%s\n", dequeue(Kolejka));
	printf("%s\n", dequeue(Kolejka));
	writeq(*Kolejka);
	printf("%s\n", dequeue(Kolejka));
	printf("%s\n", dequeue(Kolejka));
	writeq(*Kolejka);
	printf("%s\n", queueempty(*Kolejka));
	clearq(Kolejka);
	
	printf("\n\n\n==Liczba elementow - rekurencyjnie==\n");
	insert(L, 10);
	insert(L, 20);
	insert(L, 30);
	insert(L, 40);
	write(*L);
	printf("%i\n", liczbaElementowRekurencyjnie(L));
	
	printf("\n==Liczba elementow - iteracyjnie==\n");
	listdelete(L, 30);
	write(*L);
	printf("%i\n", liczbaElementowIteracyjnie(L));
	
	printf("\n==Odwracanie listy==\n");
	write(*L);
	init(Odwrocona);
	odwroc(L, Odwrocona);
	clear(L);
	free(L);
	write(*Odwrocona);
	clear(Odwrocona);
	free(Odwrocona);
	
	return 0;
	
}

