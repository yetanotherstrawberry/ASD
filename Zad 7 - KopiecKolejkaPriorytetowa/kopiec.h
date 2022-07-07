#ifndef KOPIEC
#define KOPIEC

typedef struct {
	
	int *data;
	int length;
	int heapSize;
	
} Heap;

void init(Heap *T, int *tab, int n);
void maxHeapify(Heap *T, int i);
void buildMaxHeap(Heap *T);
int heapMaximum(Heap T);
int heapExtractMax(Heap *T);
void heapIncreaseKey(Heap *T, int i, int key);
void maxHeapInsert(Heap *T, int key);
void write(Heap T);

void write_element(int a);

void minHeapify(Heap *T, int i);
void buildMinHeap(Heap *T);
void heapSort(int *tab, int a);
void writeArray(int *tab, int a);
void minHeapRemove(Heap *T, int i);
int maxHeapMinimum(Heap T);

#endif

