#ifndef __ADJL_GRAPH__
#define __ADJL_GRAPH__
//which means Adjacent List
#include "DLlist.h"
#include "stack.h"
#include "queue.h"
typedef enum vertice {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z} vertices;

typedef struct __graph{
    int num_vert;
    int num_edge;
    DList* list; //Lst of Dlists
    int * visitinfo;
}ALGraph;

void GraphInit(ALGraph*,int);
void AddEdge(ALGraph*,int,int);
void ShowGraphInfo(ALGraph*);
void FreeGraph(ALGraph*);

void BFS(ALGraph*,int);
void DFS(ALGraph*,int);

#endif 