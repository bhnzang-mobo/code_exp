#include <stdio.h>
#include "graph.h"
int main(){
    ALGraph al;
    GraphInit(&al,G);

    AddEdge(&al,A,B);
    AddEdge(&al,A,D);
    AddEdge(&al,A,C);
    AddEdge(&al,C,D);
    AddEdge(&al,D,E);
    AddEdge(&al,E,F);
    AddEdge(&al,E,G);
    printf("Depth First Search\n");
    DFS(&al,A);
    printf("\n");
    DFS(&al,D);
    return 0;
}