#include "AVLRebalance.h"
#include <stdio.h>

int BSTHeight(btNode** btroot){
    if(*btroot==NULL){
        return -1;
    }
    else{
        int left = BSTHeight(&((*btroot)->left));
        int right = BSTHeight(&((*btroot)->right));
        return left>right ? left +1: right+1 ;
    }
}

int BSTbalancefactor(btNode** btroot){
    btNode * bst = *btroot;
    if(bst == NULL){
        return -1;
    }
    else{
        return BSTHeight(&(bst->left))-BSTHeight(&(bst->right));
    }
}
void __RR(btNode ** bt){
    btNode* bst = *bt;
    btNode * tmp = GetLeftSubTree(bst->right);
    MakeLeftSubTree(bst->right,bst);
    *bt=bst->right;
    MakeRightSubTree((*bt)->left,tmp);
}
void __LL(btNode ** bt){
    btNode* bst = *bt;
    btNode * tmp = GetRightSubTree(bst->left);
    MakeRightSubTree(bst->left,bst);
    *bt=bst->left;
    MakeLeftSubTree((*bt)->right,tmp); //when root's left is not null, it had been removed in MakeLeft(Right)SubTree.
}
void __LR(btNode ** bt){
    __RR(&((*bt)->right));
    __LL(bt);
}
void __RL(btNode ** bt){
    __LL(&((*bt)->left));
    __RR(bt);
}
void Rebalancing(btNode** btroot){
    if(BSTbalancefactor(btroot)>=2 || BSTbalancefactor(btroot)<=-2 ){//rebalancing necessary
        if(BSTbalancefactor(&((*btroot)->left))>=2 || BSTbalancefactor(&((*btroot)->left))<=-2){
            Rebalancing(&((*btroot)->left));
        }
        else if(BSTbalancefactor(&((*btroot)->right))>=2 || BSTbalancefactor(&((*btroot)->right))<=-2){
            Rebalancing(&((*btroot)->right));
        }
        else{
            int count=0;
            if(BSTbalancefactor(btroot)>=2){
                count+=2;
                if(BSTbalancefactor(&((*btroot)->left))>=0){
                    count+=1;
                }
                else{
                    count-=1;
                }
            }
            else{
                count-=2;
                if(BSTbalancefactor(&((*btroot)->left))>=0){
                    count+=1;
                }
                else{
                    count-=1;
                }
            }

            switch (count)
            {
            case -3 : //__RR needed
                __RR(btroot);
                break;
            case -1 : //__RL needed
                __RL(btroot);
                break;
            case 1 : //__LR needed
                __LR(btroot);
                break;
            case 3 : // __LL needed
                __LL(btroot);
                break;
            
            default:
                break;
            }
        }
    }
    else{
        return;//no need to rebalancing.
    }
}
