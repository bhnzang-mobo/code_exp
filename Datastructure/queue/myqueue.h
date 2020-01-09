#ifndef __Queue__
#define __Queue__
typedef struct Queue {
	int capacity;
	int num;
	struct Queuenode* front, *rear;
}Queue;

typedef struct Queuenode {
	char* value;
	struct Queuenode* next;
}Queuenode;
int isEmpty(Queue*);
Queue* createQueue(int);
void enQueue(Queue* , char*);
char* deQueue(Queue*);
#endif