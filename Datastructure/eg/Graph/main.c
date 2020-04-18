#include <stdio.h>
#include "graph.h"
int main(){
    ALGraph al;
    GraphInit(&al,G);

    AddEdge(&al,A,B);
    AddEdge(&al,A,D);
    AddEdge(&al,B,C);
    AddEdge(&al,C,D);
    AddEdge(&al,D,E);
    AddEdge(&al,E,F);
    AddEdge(&al,E,G);

    DFS(&al,A);
    printf("\n");
    DFS(&al,C);
    return 0;
}