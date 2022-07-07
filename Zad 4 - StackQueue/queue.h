#ifndef QUEUE
#define QUEUE

#define ROZMIAR_KOLEJKI 10

typedef struct {
	
	int data[ROZMIAR_KOLEJKI];
	int length;
	int head;
	int tail;
	
} Queue;

void initq(Queue *Q);
int queueempty(Queue Q);
void queueemptywrite(int queueempty);
void enqueue(Queue *Q, int k);
int dequeue(Queue *Q);
void writeq(Queue Q);
int rozmiar(Queue Q);
void printq(int element);

#endif

