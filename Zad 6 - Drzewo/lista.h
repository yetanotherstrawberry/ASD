#ifndef LISTA

#define LISTA

typedef struct Element {
	
	struct Node *key;
	struct Element *next;
	struct Element *prev;
	
} Element;

typedef struct Lista {
	
	struct Element *head;
	struct Element *tail;
	
} Lista;

void initl(Lista *L);
void insert(Lista *L, struct Node *key);

#endif

