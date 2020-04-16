#include <stdio.h>
#include <malloc.h>
#include "graph.h"
//enum value starts with 0. E = 4
void GraphInit(ALGraph* al,int nv){
    al->num_vert=nv;
    al->num_edge=0;
    al->list=(DList*)malloc(sizeof(DList)*nv);
    for(int i = 0 ; i < nv+1 ; i ++){//error : i < nv
        Dinit(&(al->list[i]));
    }
}
void AddEdge(ALGraph* al,int from ,int to){
    DList* obj = &(al->list[from]);
    Dinsert(obj,to);
    obj = &(al->list[to]);
    Dinsert(obj,from);
    al->num_edge++;
}
void ShowGraphInfo(ALGraph* al){
    DData data;
    int i = 0;
    while(i<=al->num_vert){
        printf("%c to ",'A'+i);
        DList* obj = &(al->list[i++]);
        if(DFirst(obj,&data)){
            printf("%c ",'A'+data);
            while(DNext(obj,&data)){
                printf("%c ",'A'+data);
            }
        }
        printf("\n");
    }
}
void FreeGraph(ALGraph* al){
    DData data;
    int i = 0;
    while(i>=al->num_vert){
        DList* obj = &(al->list[i++]);
        if(DFirst(obj,&data)){
            DRemove(obj);
            while(DNext(obj,&data)){
                DRemove(obj);
            }
        }
        printf("\n");
    }
}