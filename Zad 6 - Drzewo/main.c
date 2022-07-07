#include <stdio.h>

#include "tree.h"

int main(void) {
	
	struct Tree T;
	init(&T);
	maketree(&T, 10);
	
	printtree(T);
	
	printf("Preorder - iteracyjnie\n");
	preordertree(T);
	
	printf("Inorder - iteracyjnie\n");
	inordertree(T);
	
	printf("Postorder - iteracyjnie\n");
	postordertree(T);
	
	printf("Liczba lisci w drzewie\n");
	printf("%i\n", leafcount(T));
	
	clear(&T);
	printtree(T);
	
	printf("Losowe drzewo w sposob rekurencyjny\n");
	make_tree_rek(&T, 10);
	printtree(T);
	
	clear(&T);
	
	return 0;
	
}

