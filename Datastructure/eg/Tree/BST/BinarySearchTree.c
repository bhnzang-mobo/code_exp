#include "BinarySearchTree.h"
#include <stdio.h>
#include <malloc.h>
void BSTinit(btNode** pbstroot){
    *pbstroot = NULL;
}
void BSTinsert(btNode** bstroot,bstdata data){
    btNode* nnode = MakeBTNode();
    SetData(nnode,data);
    btNode ** cnode = bstroot;

    btNode ** next;
    next = cnode;

    while(*next!=NULL){
        if((*cnode)->data == data){//Primary Key
            return;
        }
        cnode = next;
        next= (*cnode)->data>data?&((*cnode)->left):&((*cnode)->right);
    }

    *next=nnode;//if-then statement removed.
}
bstdata BSTGetNodeData(btNode* bstroot){
    return bstroot->data;
}
btNode* BSTsearch(btNode* bst,bstdata data){
    if(bst==NULL){
        return NULL;
    }
    if(bst->data==data){
        return bst;
    }
    else{
        if(bst->data<data){
            BSTsearch(bst->right,data);
        }
        else
        {
            BSTsearch(bst->left,data);
        }
        
    }
}
//Better than the code in the Book!!
void BSTdelete(btNode** bst, bstdata data){
    btNode* delnode, *delpnode;
    delpnode=*bst;
    delnode= delpnode;
    while(delnode !=NULL && delnode->data!=data){
        delpnode=delnode;
        delnode= delpnode->data>data?GetLeftSubTree(delpnode):GetRightSubTree(delpnode);
    }
    if(delpnode!=NULL && delnode==NULL){
        return;//There is no node with data. No deletion occur.
    }
    //Replace node search
    btNode* repnode,* prepnode;
    if(delnode->left!=NULL){
        prepnode=delnode;
        repnode=prepnode->left;
        while(repnode->right!=NULL){
            prepnode=repnode;
            repnode=repnode->right;
        }
        delnode->data=BSTRemoveNode(prepnode,repnode);
    }
    else if (delnode->right!=NULL){
        prepnode=delnode;
        repnode=prepnode->right;
        while(repnode->left!=NULL){
            prepnode=repnode;
            repnode=repnode->left;
        }
        delnode->data=BSTRemoveNode(prepnode,repnode);
    }
    else{
        if(delpnode==delnode){
            *bst=NULL;
            return;
        }
        if(delpnode->data<delnode->data){
            MakeRightSubTree(delpnode,delnode->left);
        }
        else{
            MakeLeftSubTree(delpnode,delnode->left);
        }
        
        free(delnode);
    }

    
}


/*
모든 노드의 삭제 과정은 한 개 이하의 자식 노드의 삭제 문제로
귀결된다. 삭제할 노드는 대체 노드의 정보(data)만 가져와 대입후
대체 노드를 삭제만 하면 되는데, 모든 대체노드는 leaf노드 이거나
자식이 하나인 노드이다.
삭제 대상이 루트 노드인 경우에도, 정보를 대입 후 루트 노드의 삭제로
귀결시킬 수 있기 때문에 따로 정의해주지 않아도 된다.
*/
bstdata BSTRemoveNode(btNode* pnode,btNode* node){
    bstdata ret = node->data;
    if(node->left==NULL){
        if(ret<pnode->data){
            MakeLeftSubTree(pnode,node->right);
            free(node);
            return ret;
        }
        else{
            MakeRightSubTree(pnode,node->right);
            free(node);
            return ret;
        }
        
    }
    else{
        if(ret<pnode->data){
            MakeLeftSubTree(pnode,node->left);
            free(node);
            return ret;
        }
        else{
            MakeRightSubTree(pnode,node->left);
            free(node);
            return ret;
        }
    }
}