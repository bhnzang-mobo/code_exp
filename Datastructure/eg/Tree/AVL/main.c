#include <stdio.h>
#include "BinarySearchTree.h"
#include "AVLRebalance.h"
int main(){
    btNode * bstroot;
    btNode * sNode;

    BSTinit(&bstroot);

    BSTinsert(&bstroot,3);
    BSTinsert(&bstroot,5);
    BSTinsert(&bstroot,4);

    BSTdelete(&bstroot,4);
    BSTdelete(&bstroot,3);
    sNode=BSTsearch(&bstroot,5);
    if(sNode==NULL){
        printf("탐색실패");
    }
    else{
        printf("%d ",sNode->data);
    }
    printf("\n%d ",BSTbalancefactor(&bstroot));
    return 0;
}