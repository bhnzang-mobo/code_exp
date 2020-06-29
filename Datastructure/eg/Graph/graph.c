#include <stdio.h>
#include <malloc.h>
#include "graph.h"
//enum value starts with 0. E = 4
void GraphInit(ALGraph* al,int nv){//nv is Quantity number.
    al->num_vert=nv;
    al->num_edge=0;
    //Cause of Crash.
    //Not enough allocation. it was...
    //sizeof(DLlist)*nv, which is nv+1 = al->num_vert.
    al->list=(DList*)malloc(sizeof(DList)*(al->num_vert));
    al->visitinfo=(int*)malloc(sizeof(int)*(al->num_vert));
    for(int i = 0 ; i < al->num_vert ; i ++){//error : i < nv
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
    while(i<=al->num_vert-1){
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
    while(i<=al->num_vert){
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


int haveVisited(int list [], int k){
    if(list[k]==1) return 1;
    else return 0;
}
void VisitVert(ALGraph* al, int visit){
    al->visitinfo[visit]=1;
    printf("%c Refered.\n",'A'+visit);
}

void DFS(ALGraph* al,int start){
    DData next,origin;
    DList * obj,*start_obj;
    Stack stack;
    int i = 0;
    start_obj=&(al->list[start]);
    
    while(i < al->num_vert){
        DFirst(&(al->list[i]),&next);
        i++;
    }

    for(int i = 0 ; i < al->num_vert ; i ++){
        al->visitinfo[i]=0;
    }

    Stackinit(&stack);
    Push(&stack,start);
    VisitVert(al,start);    
    origin=Peek(&stack);
    al->visitinfo[origin]=1;

    obj=&(al->list[start]);
    next=start;

    /*
    while(haveVisited(al->visitinfo,next)){//What's next?
        DNext(obj,&next);
    }
    obj=&(al->list[next]);
    printf("%c Refered.\n",'A'+next);
    */

    while(!isEmpty(&stack) || obj->cur->right!=obj->tail){
        origin=next;
        DFirst(obj,&next);
        while(haveVisited(al->visitinfo,next)){//What's next?
            if(!DNext(obj,&next)) break;
        }
        if(!haveVisited(al->visitinfo,next)){ //Yes Next
            Push(&stack,origin);
            VisitVert(al,next);
            obj=&(al->list[next]);
            continue;
        }
        else{ //No next
            if(!isEmpty(&stack)){
                next=Pop(&stack);
                obj=&(al->list[next]);
            }
        }
    }
}

void BFS(ALGraph* al, int start){
    //init
    DData originV,nextV;
    DList* obj;
    queue alque;
    queueinit(&alque);

    for(int i = 0 ; i < al->num_vert ; i ++){
        al->visitinfo[i]=0;
    }

    enqueue(&alque,start);
    VisitVert(al,start);
    obj= &(al->list[start]);
    
    while(!isQEmpty(&alque)){
        nextV=dequeue(&alque);
        obj=&(al->list[nextV]);
        DFirst(obj,&nextV);
        if(!haveVisited(al->visitinfo,nextV)){
            VisitVert(al,nextV);
            enqueue(&alque,nextV);
        }
        while(DNext(obj,&nextV)){
            if(!haveVisited(al->visitinfo,nextV)){
                VisitVert(al,nextV);
                enqueue(&alque,nextV);
            }
        }
    }

}