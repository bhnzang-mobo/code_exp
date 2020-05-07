#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "pqueue.h"
int Datacomp(Hdata a, Hdata b){
    if(a>b) return 0;
    else return 1;
}


int main(){
    PQueue hp;
    PQueueIint(&hp,Datacomp);
    printf("%d\n",isheapEmpty(&hp));
    PEnqueue(&hp,9);
    PEnqueue(&hp,2);
    PEnqueue(&hp,12);
    PEnqueue(&hp,8);
    PEnqueue(&hp,6);
    PEnqueue(&hp,111);
    PEnqueue(&hp,4);
    PEnqueue(&hp,3);
    PEnqueue(&hp,7);
    PEnqueue(&hp,13);
    /*
    for(int i = 0 ; i < 6 ; i ++){
        PEnqueue(&hp,data+i,i-2*(i%2)+1);
        printf("pr = %d, %c \n",i-2*(i%2)+1,data+i);
    }
    */

    while(!isheapEmpty(&hp)){
        printf("%d ",PDequeue(&hp));
    }
}