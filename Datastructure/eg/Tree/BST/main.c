#include <stdio.h>
#include "BinarySearchTree.h"

int main(){
    btNode * bstroot;
    btNode * sNode;

    BSTinit(&bstroot);

    BSTinsert(&bstroot,12);
    BSTinsert(&bstroot,8);
    BSTinsert(&bstroot,4);
    BSTinsert(&bstroot,9);
    BSTinsert(&bstroot,2);
    BSTinsert(&bstroot,7);
    BSTinsert(&bstroot,13);
    
    BSTdelete(&bstroot,12);
    if(sNode==NULL){
        printf("탐색실패");
    }
    else{
        printf("%d",sNode->data);
    }
    return 0;
}