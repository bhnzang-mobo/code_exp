#include <stdio.h>
#include "BinarySearchTree.h"
#include "AVLRebalance.h"
int main(){
    btNode * bstroot;
    btNode * sNode;

    BSTinit(&bstroot);

    BSTinsert(&bstroot,3);
    BSTinsert(&bstroot,4);
    BSTinsert(&bstroot,2);
    BSTinsert(&bstroot,1);
    BSTinsert(&bstroot,5);
    BSTinsert(&bstroot,0);
    BSTinsert(&bstroot,6);
    
    BSTdelete(&bstroot,3);
    BSTinsert(&bstroot,-1);
    sNode = BSTsearch(&bstroot,4);
    if(sNode==NULL){
        printf("탐색실패");
    }
    else{
        printf("%d ",sNode->data);
    }
    printf("\n%d ",BSTbalancefactor(&bstroot));
    return 0;
}