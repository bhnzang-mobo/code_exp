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
void GraphInit(ALGraph* al,int nv){//nv is Quantity number.
    al->num_vert=nv;
    al->num_edge=0;
    //Cause of Crash.
    //Not enough allocation. it was...
    //sizeof(DLlist)*nv, which is nv+1 = al->num_vert.
    
    al->list=(DList*)malloc(sizeof(DList)*(al->num_vert));
    al->visitinfo=(int*)malloc(sizeof(int)*(al->num_vert));
    for(int i = 0 ; i < nv ; i ++){//error : i < nv
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
    DData data;
    DList * obj,*start_obj;
    Stack stack;
    
    int i = 0;
    while(i < al->num_vert){
        DFirst(&(al->list[i]),&data);
        i++;
    }
    for(int i = 0 ; i < al->num_vert ; i ++){
        al->visitinfo[i]=0;
    }

    

    /*
    int next,origin;
    Stackinit(&stack);

    Push(&stack,start);
    VisitVert(al,start);
    obj=&(al->list[start]);
    next=start;
    
    
        
    origin=Peek(&stack);

    while(haveVisited(al->visitinfo,next)){//What's next?
        DNext(obj,&next);
    }
    obj=&(al->list[next]);
    printf("%c Refered.\n",'A'+next);
    */
   //원래 구성하던 방식은 현재노드 push, 과거 노드 pop, 과거노드 peek(열람,쓸일 없음)
   //따라서 과거 node pop을 할 경우가 되는경우는 현재 노드에 갈 곳이 없는경우.
   //isempty는 돌아갈 곳이 없는 경우가 됨.
   //start로 되돌아간 경우, isempty에 걸려 탈출.
   //현재 노드에 갈 곳이 없는 경우, 과거로 되돌아가려면 start에서 갈곳을 만들어야함
   //따라서 가상의 시작노드를 만들어 가상 노드가 시작 노드를 가리키고 있도록함.
   /*아래 방식이 위에서 기술한 논리
    while(!isEmpty(&stack)){
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
    }*/
    //아래 방식은 다음노드 push, 다음노드 visit, 과거노드 회수를 pop & peek로 설정해 구성한경우
    //peek는 현재 노드를 의미하며 pop&peek할 경우 과거노드를 회수할 수 있음
    //따라서 isempty의 의미는 마지막 노드(시작노드)가 더이상 갈 곳이 없어 pop하여 탐색이 종료된 경우를 의미함
    //위 방식과 다르게 가상의 노드를 참조하는 경우는 없음. 하지만 초기값 설정을 위해 start를 push함
    //다음 노드가 어디인지만 판단하면 되므로 현재 노드를 가리키는 origin 변수는 필요 없음.
    int next;
    Stackinit(&stack);

    Push(&stack,start);
    VisitVert(al,start);
    obj=&(al->list[start]);
    next=start;
        

    while(!isEmpty(&stack)){
        DFirst(obj,&next);
        while(haveVisited(al->visitinfo,next)){//What's next?
            if(!DNext(obj,&next)) break;
        }
        if(!haveVisited(al->visitinfo,next)){ //Yes Next
            Push(&stack,next);
            VisitVert(al,next);
            obj=&(al->list[next]);
            continue;
        }
        else{ //No next
            if(!isEmpty(&stack)){
                Pop(&stack);
                if(!isEmpty(&stack)) next=Peek(&stack);
                obj=&(al->list[next]);
            }
        }
    }
}

void BFS(ALGraph* al, int start){
    //init
    int nextV;
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
