#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void heapinit(heap* hp,Prioritycomp comp){
    hp->numOfData=0;
    hp->comp=comp;
}
int isheapEmpty(heap * hp){
    if(hp->numOfData==0) return 1;
    else return 0;
}
void heapinsert(heap* hp, Hdata data){
    int idx = hp->numOfData+1;
    //useless : hp->heaparr[idx].pr=pr;
    while(idx>=2){
        int rt = idx/2;
        if(hp->comp(data,hp->heaparr[rt])){//1 for data, 0 for rt is primary.
            hp->heaparr[idx]=hp->heaparr[rt]; //let rt goes down.
        }
        else{
            break;
        }
        idx/=2;
    }
    hp->heaparr[idx]=data;
    hp->numOfData++;
}
Hdata heapDelete(heap* hp){
    int idx = 1;
    Hdata deldata = hp->heaparr[1];
    int mv;
    while(2*idx<hp->numOfData){
        if(2*idx==hp->numOfData) mv= 2*idx;//if the is a one child (left one)
        else mv = hp->comp(hp->heaparr[2*idx+1],hp->heaparr[2*idx]) ? 2*idx+1 : 2*idx; //1 for right, 0 for left
        
        //useless if(hp->heaparr[idx].pr>hp->heaparr[mv].pr){
        if(hp->comp(hp->heaparr[mv],hp->heaparr[hp->numOfData])){
            hp->heaparr[idx]=hp->heaparr[mv]; //let mv goes up
        }
        else{
            break;
        }
        idx=mv; //idx/=2; (X) Because heap does not always match rule that left child has higher priority than right one.
    }
    hp->heaparr[idx]=hp->heaparr[hp->numOfData--];
    return deldata;
}