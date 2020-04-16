#include <stdio.h>
#include "graph.h"
int main(){
    ALGraph al;
    GraphInit(&al,E);

    AddEdge(&al,A,B);
    AddEdge(&al,A,C);
    AddEdge(&al,B,C);
    AddEdge(&al,B,D);
    AddEdge(&al,C,E);

    ShowGraphInfo(&al);
    
    return 0;
}