#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

void init(Lista *L){
	
	L -> head = NULL;
	L -> tail = NULL;
	
	return;
	
}

void insert(Lista *L, int k){
	
	Element *x = malloc(sizeof(Element));
	x -> key = k;
	x -> prev = NULL;
	
	if(L -> head == NULL){

		x -> next = NULL;
		L -> head = x;
		L -> tail = x;
		
	}
	else {
		
		x -> next = L -> head;
		L -> head -> prev = x;
		L -> head = x;
		
	}
	
	return;
	
}

void write(Lista L){
	
	Element *x = L.head;
	
	while(x != NULL){
		
		printf("%d ", x -> key);
		x = x -> next;
		
	}
	
	printf("\n");
	
	return;
	
}

Element *search(Lista L, int k){
	
	Element *x = L.head;
	
	while(x != NULL && x -> key != k) x = x -> next;
	
	return x;
	
}

void insertAfter(Lista *L, int j, int k){
	
	Element *wskaznik = search(*L, k);
	
	Element *x = malloc(sizeof(Element));
	x -> key = j;
	
	if(wskaznik == NULL){
		
		printf("Nie ma takiego elementu!\n");
		return;
		
	}
	
	if(wskaznik == L -> tail) L -> tail = x;

	x -> next = wskaznik -> next;
	x -> prev = wskaznik;
	wskaznik -> next = x;
	
	return;
	
}

void insertBefore(Lista *L, int j, int k){
	
	Element *wskaznik = search(*L, k);
	
	Element *x = malloc(sizeof(Element));
	x -> key = j;
	
	if(wskaznik == NULL){
		
		printf("Nie ma takiego elementu!\n");
		return;
		
	}
	
	if(wskaznik == L -> head) L -> head = x;
	
	x -> next = wskaznik;
	x -> prev = wskaznik -> prev;
	if(wskaznik -> prev != NULL) wskaznik -> prev -> next = x;
	if(wskaznik -> prev != NULL) wskaznik -> prev = x;
	
	return;
	
}

void listdelete(Lista *L, int k){
	
	Element *wskaznik = search(*L, k);
	
	if(wskaznik != NULL) {
		
		if(wskaznik == L -> head) L -> head = wskaznik -> next;
		if(wskaznik == L -> tail) L -> tail = wskaznik -> prev;
		
		if(wskaznik -> prev != NULL) wskaznik -> prev -> next = wskaznik -> next;
		if(wskaznik -> next != NULL) wskaznik -> next -> prev = wskaznik -> prev;
		
		free(wskaznik);
		
	}

	return;
	
}

void clear(Lista *L){
	
	Element *x;
	Element *nast = L -> head;
	
	while(nast != NULL){
		
		x = nast;
		nast = x -> next;
		free(x);
		
	}
	
	L -> head = NULL;
	L -> tail = NULL;
	
	return;
	
}

int Rekurencja(Element *E){
	
	if(E -> next != NULL) return 1 + Rekurencja(E -> next);
	else return 1;
	
}

int liczbaElementowRekurencyjnie(Lista *L){
	
	if(L -> head != NULL) return Rekurencja(L -> head);
	else return 0;
	
}

int liczbaElementowIteracyjnie(Lista *L){
	
	int suma = 0;
	Element *x = L -> head;
	
	while(x != NULL){
		
		suma++;
		x = x -> next;
		
	}
	
	return suma;
	
}

void odwroc(Lista *L, Lista *Odwrocona){
	
	Element *x = L -> head;
	
	while(x != NULL){
		
		insert(Odwrocona, x -> key);
		x = x -> next;
		
	}
	
	return;
	
}

void write_search(struct Element *e){
	
	if(e != NULL) printf("%i\n", e -> key);
	else printf("-1\n");
	
	return;
	
}
