#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "pqueue.h"
int Datacomp(Hdata a, Hdata b){
    if(strlen(a)<strlen(b)) return 0;
    else return 1;
}


int main(){
    PQueue hp;
    PQueueIint(&hp,Datacomp);
    printf("%d\n",isheapEmpty(&hp));
    PEnqueue(&hp,"Hello ");
    PEnqueue(&hp,"World~! ");
    PEnqueue(&hp,"Good Night");
    /*
    for(int i = 0 ; i < 6 ; i ++){
        PEnqueue(&hp,data+i,i-2*(i%2)+1);
        printf("pr = %d, %c \n",i-2*(i%2)+1,data+i);
    }
    */

    while(!isheapEmpty(&hp)){
        printf("%s",PDequeue(&hp));
    }
}