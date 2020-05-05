#ifndef __ADJL_KRUSKAL_GRAPH__
#define __ADJL_KRUSKAL_GRAPH__
//which means Adjacent List
#include "DLlist.h"
#include "stack.h"
#include "queue.h"
#include "ALEdge.h"
#include "pqueue.h"

typedef enum vertice {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z} vertices;

typedef struct __graph{
    int num_vert;
    int num_edge;
    DList* list; //Lst of Dlists
    int * visitinfo;
    pqueue pque;
    
}ALGraph;

void GraphInit(ALGraph*,int);
void AddEdge(ALGraph*,int,int,int);
void ShowGraphInfo(ALGraph*);
void FreeGraph(ALGraph*);

void ConKruskal(ALGraph* al);
void ShowGraphEdgeWeightInfo(ALGraph * al);
void BFS(ALGraph*,int);
void DFS(ALGraph*,int);

#endif 