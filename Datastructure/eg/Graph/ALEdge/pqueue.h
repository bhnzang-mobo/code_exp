#ifndef __P_QUEUE__
#define __P_QUEUE__
#include "heap.h"
typedef heap PQueue;
typedef Hdata PQData;
typedef heap pqueue;

void PQueueInit(heap* hp, Prioritycomp cmp);
int isPQEmpty(heap* hp);
void PEnqueue(heap* hp, PQData data);
PQData PDequeue(heap* hp);

#endif