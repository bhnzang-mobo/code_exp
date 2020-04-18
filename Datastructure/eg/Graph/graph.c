#include <stdio.h>
#include <malloc.h>
#include "graph.h"
//enum value starts with 0. E = 4
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
    for(int i = 0 ; i < nv+1 ; i ++){
        al->visitinfo[i]=0;
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

    Stackinit(&stack);
    Push(&stack,start);
    printf("%c Refered.\n",'A'+start);
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
        al->visitinfo[origin]=1;
        DFirst(obj,&next);
        while(haveVisited(al->visitinfo,next)){//What's next?
            if(!DNext(obj,&next)) break;
        }
        if(!haveVisited(al->visitinfo,next)){ //Yes Next
            Push(&stack,origin);
            printf("%c Refered.\n",'A'+next);
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
