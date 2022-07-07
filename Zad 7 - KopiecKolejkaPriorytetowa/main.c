#include <stdio.h>
#include <stdlib.h>

#include "kopiec.h"

int main(void) {
	
	int do_sortowania[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int tab[20] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	Heap *T = malloc(sizeof(Heap));
	init(T, tab, 10);
	buildMaxHeap(T);
	write(*T);
	maxHeapInsert(T, 15);
	write(*T);
	write_element(heapMaximum(*T));
	write(*T);
	write_element(heapExtractMax(T));
	write(*T);
	heapIncreaseKey(T, 4, 19);
	write(*T);
	
	printf("===najmniejszy elementa kopca max===\n");
	write_element(maxHeapMinimum(*T));
	printf("===minHeapify===\n");
	minHeapify(T, 0);
	write(*T);
	printf("===buildMinHeap===\n");
	buildMinHeap(T);
	write(*T);
	printf("===heapSort===\n");
	writeArray(do_sortowania, 10);
	heapSort(do_sortowania, 10);
	writeArray(do_sortowania, 10);
	printf("===usuwanie i-tego elementu===\n");
	minHeapRemove(T, 3);
	write(*T);
	
	return 0;
	
}

