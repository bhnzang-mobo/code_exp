#include <stdio.h>
#include "pqueue.h"
void PQueueInit(heap* hp, Prioritycomp cmp){
    heapinit(hp,cmp);
}
int isPQEmpty(heap* hp){
    return isheapEmpty(hp);
}
void PEnqueue(heap* hp, PQData data){
    heapinsert(hp,data);
}
PQData PDequeue(heap* hp){
    if(!isPQEmpty(hp)) return heapDelete(hp);
}