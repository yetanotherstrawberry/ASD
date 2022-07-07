#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main(void) {
	
	struct Tree *T = malloc(sizeof(struct Tree));
	init(T);
	treeInsert(T, 15);
	treeInsert(T, 5);
	treeInsert(T, 16);
	treeInsert(T, 3);
	treeInsert(T, 12);
	treeInsert(T, 20);
	treeInsert(T, 10);
	treeInsert(T, 6);
	treeInsert(T, 7);
	treeInsert(T, 13);
	treeInsert(T, 18);
	treeInsert(T, 23);
	writeTree(*T);
	write(*treeSearchRecursive(*T, 13));
	write(*treeSearchIterative(*T, 13));
	write(*treeSuccessor(treeSearchRecursive(*T, 5)));
	write(*treeSuccessor(treeSearchRecursive(*T, 13)));
	treeDelete(T, 13);
	writeTree(*T);
	treeDelete(T, 16);
	writeTree(*T);
	treeDelete(T, 5);
	writeTree(*T);
	clear(T);
	writeTree(*T);
	
	treeInsert(T, 15);
	treeInsert(T, 5);
	treeInsert(T, 16);
	treeInsert(T, 3);
	treeInsert(T, 12);
	treeInsert(T, 20);
	treeInsert(T, 10);
	treeInsert(T, 6);
	treeInsert(T, 7);
	treeInsert(T, 13);
	treeInsert(T, 18);
	treeInsert(T, 23);
	printf("===treeMinimum===\n");
	write(*treeMinimum(*T));
	printf("===treeMaximum===\n");
	write(*treeMaximum(*T));
	printf("===treePredecessor===\n");
	write(*treePredecessor(treeMaximum(*T)));
	printf("===nastepnik najmniejszego===\n");
	write(*smallestSuccessor(*T));
	clear(T);
	free(T);
	
	return 0;
	
}

