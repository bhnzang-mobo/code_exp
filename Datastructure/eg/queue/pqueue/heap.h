#ifndef __HEAP__
#define __HEAP__
#define heaplen 100
typedef int Hdata;
typedef int Priority;
typedef int (*Prioritycomp)(Hdata,Hdata);


typedef struct heap{
    Prioritycomp comp;
    int numOfData;
    Hdata heaparr[heaplen];
}heap;

void heapinit(heap* hp,Prioritycomp);
int isheapEmpty(heap * hp);
void heapinsert(heap* hp, Hdata data);
Hdata heapDelete(heap* hp);

#endif