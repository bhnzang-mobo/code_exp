#include <stdio.h>
#include "graphKruskal.h"
int main(){
    ALGraph al;
    GraphInit(&al,F+1);

    AddEdge(&al,A,B,9);
    AddEdge(&al,B,C,2);
    AddEdge(&al,A,C,12);
    AddEdge(&al,A,D,8);
    AddEdge(&al,D,C,6);
    AddEdge(&al,A,F,111);
    AddEdge(&al,F,D,4);
    AddEdge(&al,D,E,3);
    AddEdge(&al,E,C,7);
    AddEdge(&al,F,E,13);
    ShowGraphInfo(&al);

    printf("Depth First Search\n");
    BFS(&al,C);
    printf("\nConstitue Kruskal\n");
    ConKruskal(&al);
    ShowGraphInfo(&al);
    return 0;
}