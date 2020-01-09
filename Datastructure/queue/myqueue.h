#ifndef __Queue__
#define __Queue__

typedef int QData;

typedef struct Queue {
	int capacity;
	int num;
	struct Queuenode* front, *rear;
}Queue;

typedef struct Queuenode {
	QData value;
	struct Queuenode* next;
}Queuenode;

void initQueue(Queue*,int);
void enQueue(Queue* , QData);
QData deQueue(Queue*);

void freeQueue(Queue*);
Queuenode* getQFront(Queue*);
Queuenode* getQRear(Queue*);
int isFull(Queue);
int isEmpty(Queue);
#endif