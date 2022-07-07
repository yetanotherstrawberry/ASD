#include <stdio.h>
#include <stdlib.h>

#include "kopiec.h"

void init(Heap *T, int tab[], int n) {
	
	T -> data = tab;
	T -> heapSize = n;
	T -> length = n;
	
	return;
	
}

int parent(int i) {
	
	return i / 2;
	
}

int left(int i) {
	
	return (i * 2) + 1;
	
}

int right(int i) {
	
	return (i * 2) + 2;
	
}

void swap(Heap *T, int a, int b) {
	
	int temp = T -> data[a];
	
	T -> data[a] = T -> data[b];
	T -> data[b] = temp;
	
	return;
	
}

void bottomUpHeapify(Heap *T, int i) {
	
	if(T -> data[parent(i - 1)] < T -> data[i]) swap(T, parent(i - 1), i);
	if(parent(i - 1) != parent(parent(i - 1))) bottomUpHeapify(T, parent(i - 1));
	
	return;
	
}

void heapIncreaseKey(Heap *T, int i, int key) {
	
	i--;
	
	T -> data[i] = key;
	
	bottomUpHeapify(T, i);
	
	return;
	
}

void maxHeapInsert(Heap *T, int key) {
	
	T -> length++;
	T -> heapSize++;
	T -> data[T -> heapSize - 1] = key;
	bottomUpHeapify(T, T -> heapSize - 1);
	
	return;
	
}

void maxHeapify(Heap *T, int i) {
	
	int left_child = left(i), right_child = right(i), largest = i;
	
	if(left_child < T -> heapSize && T -> data[left_child] > T -> data[largest]) largest = left_child;
	if(right_child < T -> heapSize && T -> data[right_child] > T -> data[largest]) largest = right_child;
	
	if(largest != i){
		
		swap(T, i, largest);
		maxHeapify(T, largest);
		
	}
	
	return;
	
}

void buildMaxHeap(Heap *T) {
	
	int i;
	
	for(i = (T -> heapSize / 2); i >= 0; i--) maxHeapify(T, i);
	
	return;
	
}

int heapMaximum(Heap T) {
	
	return T.data[0];
	
}

int heapExtractMax(Heap *T) {
	
	int do_zwrotu = heapMaximum(*T);
	
	swap(T, 0, T -> heapSize - 1);
	
	T -> length--;
	T -> heapSize--;
	
	buildMaxHeap(T);
	
	return do_zwrotu;
	
}

void write(Heap T) {
	
	int i;
	
	for(i = 0; i < T.heapSize; i++) printf("%i ", T.data[i]);
	printf("\n");
	
	return;
	
}

void write_element(int a) {
	
	printf("%i\n", a);
	
	return;
	
}

void minHeapify(Heap *T, int i) {
	
	int left_child = left(i), right_child = right(i), smallest = i;
	
	if(left_child < T -> length && T -> data[left_child] < T -> data[smallest]) smallest = left_child;
	if(right_child < T -> length && T -> data[right_child] < T -> data[smallest]) smallest = right_child;
	
	if(smallest != i){
		
		swap(T, i, smallest);
		minHeapify(T, smallest);
		
	}
	
	return;
	
}

void buildMinHeap(Heap *T) {
	
	int i;
	
	for(i = (T -> heapSize / 2); i >= 0; i--) minHeapify(T, i);
	
	return;
	
}

void heapSort(int *tab, int a) {
	
	int i, recovery;
	Heap *T = malloc(sizeof(Heap));
	init(T, tab, a);
	
	recovery = T -> heapSize;
	
	buildMaxHeap(T);
	
	for(i = recovery - 1; i >= 0; i--){
		
		swap(T, 0, i);
		T -> heapSize--;
		maxHeapify(T, 0);
		
	}
	
	free(T);
	
	return;
	
}

void writeArray(int *tab, int a) {
	
	int i;
	
	for(i = 0; i < a; i++) printf("%i ", tab[i]);
	printf("\n");
	
	return;
	
}

void minHeapRemove(Heap *T, int i) {
	
	i--;
	swap(T, i, T -> heapSize - 1);
	T -> heapSize--;
	T -> length--;
	minHeapify(T, i);
	
}

int maxHeapMinimum(Heap T) {
	
	int i = T.heapSize / 2, min = T.data[i];
	
	while(i < T.heapSize) {
		
		if(T.data[i] < min) min = T.data[i];
		i++;
		
	}

	return min;
	
}

