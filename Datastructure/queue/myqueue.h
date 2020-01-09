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
int isEmpty(Queue*);
Queue* createQueue(int);
void enQueue(Queue* , QData);
QData deQueue(Queue*);

void freeQueue(Queue*);
Queuenode* getQFront(Queue*);
Queuenode* getQRear(Queue*);

#endif