#ifndef LISTA

#define LISTA

typedef struct Element {
	
	int key;
	struct Element *next;
	struct Element *prev;
	
} Element;

typedef struct Lista {
	
	struct Element *head;
	struct Element *tail;
	
} Lista;

void init(Lista *L);
void insert(Lista *L, int key);
void write(Lista L);
struct Element *search(Lista L, int k);
void insertAfter(Lista *L, int j, int k);
void insertBefore(Lista *L, int j, int k);
void listdelete(Lista *L, int k);
void clear(Lista *L);
int liczbaElementowRekurencyjnie(Lista *L);
int liczbaElementowIteracyjnie(Lista *L);
void odwroc(Lista *L, Lista *Odwrocona);
void write_search(struct Element *e);

#endif

