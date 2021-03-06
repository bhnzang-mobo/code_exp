#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
//comp(a,b) a>b : 0, a<b : 1;
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
    int rt;
    //useless : hp->heaparr[idx].pr=pr;
    while(idx>=2){
        rt = idx/2;
        if(hp->comp(data,hp->heaparr[rt])){
            hp->heaparr[idx]=hp->heaparr[rt]; //let rt goes down.
        }
        else{
            break;
        }
        idx=rt;
    }
    hp->heaparr[idx]=data;
    hp->numOfData++;
}
Hdata heapDelete(heap* hp){
    int idx = 1;
    int mv;

    Hdata deldata = hp->heaparr[1];
    Hdata data = hp->heaparr[hp->numOfData--];//By doing this, same node comparison could be avoided
    
    while(2*idx<=hp->numOfData){
        if(2*idx==hp->numOfData) mv= 2*idx;//if the is a one child (left one)
        else mv = hp->comp(hp->heaparr[2*idx],hp->heaparr[2*idx+1]) ? 2*idx : 2*idx+1; //if there is two children
        
        //useless if(hp->heaparr[idx].pr>hp->heaparr[mv].pr){
        if(hp->comp(hp->heaparr[mv],data)){
            hp->heaparr[idx]=hp->heaparr[mv]; //let mv goes up
        }
        else{
            break;
        }
        idx=mv; //idx/=2; (X) Because heap does not always match rule that left child has higher priority than right one.
    }
    hp->heaparr[idx]=data;
    return deldata;
}