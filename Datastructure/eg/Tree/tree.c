#include <stdio.h>
#include "tree.h"
#include <malloc.h>
btNode* MakeBTNode(){
	btNode* newnode = (btNode*)malloc(sizeof(btNode));
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
btdata GetData(btNode* node){
	return node->data;
}
void SetData(btNode* node,btdata data){
	node->data=data;
}

btNode* GetLeftSubTree(btNode* node){
	return node->left;
}
btNode* GetRightSubTree(btNode* node){
	return node->right;
}

void MakeLeftSubTree(btNode* node, btNode* sub){
	if(node->left!=NULL){
		free(node->left);
	}
	node->left=sub;
}
void MakeRightSubTree(btNode* node, btNode* sub){
	if(node->right!=NULL){
		free(node->right);
	}
	node->right=sub;
}
