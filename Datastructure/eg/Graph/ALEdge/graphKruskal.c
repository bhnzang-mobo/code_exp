#include <stdio.h>
#include <malloc.h>
#include "graphKruskal.h"
//enum value starts with 0. E = 4
int PQWeightComp(Edge a, Edge b){ //int type? new Edge type?
    if(b.weight>a.weight){
        return 1;
    }
    return 0; //1: a>b 0 : a<b
}
void GraphInit(ALGraph* al,int nv){//nv is index number.
    al->num_vert=nv+1;
    al->num_edge=0;
    //Cause of Crash.
    //Not enough allocation. it was...
    //sizeof(DLlist)*nv, which is nv+1 = al->num_vert.
    al->list=(DList*)malloc(sizeof(DList)*(al->num_vert));
    al->visitinfo=(int*)malloc(sizeof(int)*(al->num_vert));
    for(int i = 0 ; i < nv+1 ; i ++){//error : i < nv
        Dinit(&(al->list[i]));
    }
    PQueueInit(&(al->pque),PQWeightComp);
    
}
void AddEdge(ALGraph* al,int from ,int to, int weight){
    DList* obj = &(al->list[from]);
    Dinsert(obj,to);
    obj = &(al->list[to]);
    Dinsert(obj,from);
    al->num_edge++;
    PQueue *pq = &(al->pque);
    Edge data = {from,to,weight};

    PEnqueue(pq,data);

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
    int next,origin;
    DData data;
    DList * obj,*start_obj;
    Stack stack;
    int i = 0;
    start_obj=&(al->list[start]);
    
    while(i < al->num_vert){
        DFirst(&(al->list[i]),&data);
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
    int originV,nextV;
    DData data;
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
        if(DFirst(obj,&nextV)){
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

}

int isConnect(ALGraph* al){
    BFS(al,A);
    for(int i = 0 ; i < al->num_vert ; i ++){
        if(al->visitinfo[i]==0){
            return 0;
        }
    }
    return 1;
}

void ConKruskal(ALGraph * al){
    if(isPQEmpty(&(al->pque))){
        return;
    }
    PQueue pq = al->pque;
    
    while(al->num_vert<al->num_edge+1){
        //1.delete
        PQData data = PDequeue(&pq);
        int from = data.v1;
        int to = data.v2;
        int comp;
        DFirst(&(al->list[from]),&comp);
        if(to==comp){
            DRemove(&(al->list[from]));
        }
        else{
            while(DNext(&(al->list[from]),&comp)){
                if(to==comp){
                    DRemove(&(al->list[from]));
                    break;
                }
            }  
        }
        DFirst(&(al->list[to]),&comp);
        if(from==comp){
            DRemove(&(al->list[to]));
        }
        else{
            while(DNext(&(al->list[to]),&comp)){
                if(from==comp){
                    DRemove(&(al->list[to]));
                    break;
                }
            }  
        }
        al->num_edge--;
        //2.connection test
        if(isConnect(al)){
            continue;
        }
        else{
            DList* obj = &(al->list[from]);
            Dinsert(obj,to);
            obj = &(al->list[to]);
            Dinsert(obj,from);
            al->num_edge++;
        }
        //2.1 success = continue
        //2.2 fail = undo delete and continue
    }
}
