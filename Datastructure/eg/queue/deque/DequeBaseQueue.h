#ifndef __DBQ__
#define __DBQ__
#include "Deque.h"

void Queueinit(deque*);
int isQEmpty(deque*);
void Enqueue(deque*, ddata);
ddata Dequeue(deque*);
ddata Peek(deque*);

#endif