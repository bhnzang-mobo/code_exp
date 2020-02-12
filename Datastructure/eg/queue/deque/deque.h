#ifndef __DEQUE__
#define __DEQUE__

typedef int ddata;

typedef struct node{
	ddata data;
	struct node * prev;
	struct node * next;
}node;

typedef struct deque{
	node* front;
	node* rear;
	int count;
}deque;

void Dequeinit(deque*);
void Fenqueue(deque*,ddata);
void Renqueue(deque*,ddata);
ddata Fdequeue(deque*);
ddata Rdequeue(deque*);
ddata DQGetFirst(deque*);
ddata DQGetLast(deque*);
int isDQEmpty(deque*);

#endif