#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct __expo{
    int x;
    int y;
}expo;

typedef expo Hdata;
typedef int Priority;
typedef int (*Prioritycomp)(Hdata,Hdata);


typedef struct heap{
    Prioritycomp comp;
    int numOfData;
    Hdata heaparr[100010];
}heap;

void heapinit(heap* hp,Prioritycomp);
int isheapEmpty(heap * hp);
void heapinsert(heap* hp, Hdata data);
Hdata heapDelete(heap* hp);

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
        if(!hp->comp(hp->heaparr[rt],data)){//data = idx 0 : rt 1: data is primary.
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
        else mv = !hp->comp(hp->heaparr[2*idx],hp->heaparr[2*idx+1]) ? 2*idx+1 : 2*idx; //if there is two children
        
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
int expocom(Hdata a, Hdata b){
    if(a.x<b.x) return 1;
    else if(a.x==b.x){
      if(a.y<b.y) return 1;
        else return 0;
    }
    else return 0;
}
int main (){
    int num;
    int x,y;
    heap hp;
    heapinit(&hp,expocom);
    scanf("%d",&num);
    for(int i = 0 ; i < num ; i ++){
        scanf("%d %d",&x,&y);
        Hdata exp ={x,y};
        heapinsert(&hp,exp);
    }
    while(!isheapEmpty(&hp)){
        Hdata data = heapDelete(&hp);
        printf("%d %d\n",data.x,data.y);
    }
    return 0;
}