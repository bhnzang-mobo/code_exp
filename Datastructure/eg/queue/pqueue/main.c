#include <stdio.h>
#include <malloc.h>
#include "heap.h"
int Datacomp(Hdata a, Hdata b){
    if(a<b) return 0;
    else return 1;
}


int main(){
    heap  hp;
    heapinit(&hp,Datacomp);
    printf("%d\n",isheapEmpty(&hp));
    char data = 'A';
    heapinsert(&hp,data);
    heapinsert(&hp,data+1);
    heapinsert(&hp,data+2);
    heapinsert(&hp,data+3);
    heapinsert(&hp,data+4);
    heapinsert(&hp,data+5);
    /*
    for(int i = 0 ; i < 6 ; i ++){
        heapinsert(&hp,data+i,i-2*(i%2)+1);
        printf("pr = %d, %c \n",i-2*(i%2)+1,data+i);
    }
    */

    while(!isheapEmpty(&hp)){
        printf("%c",heapDelete(&hp));
    }
}