#ifndef __QUEUE__
#define __QUEUE__

typedef int qdata;

typedef struct node{
	qdata data;
	struct node* next;
}node;

typedef struct queue{
	int count;
	node* head;
	node* tail;
}queue;

void queueinit(queue*);
void enqueue(queue*,qdata);
qdata dequeue(queue*);
qdata qpeek(queue*);
int isQEmpty(queue*);

#endif