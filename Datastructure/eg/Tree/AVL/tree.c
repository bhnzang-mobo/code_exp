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

	node->left=sub;
}
void MakeRightSubTree(btNode* node, btNode* sub){

	node->right=sub;
}

void PreorderTraverse(btNode* node, VisitAction action){
	if(node==NULL){
		return;
	}
	action(node->data);
	PreorderTraverse(node->left,action);
	PreorderTraverse(node->right,action);
}
void InorderTraverse(btNode* node, VisitAction action){
	if(node==NULL){
		return;
	}
	InorderTraverse(node->left,action);
	action(node->data);
	InorderTraverse(node->right,action);
	
}
void PostorderTraverse(btNode* node, VisitAction action){
	if(node==NULL){
		return;
	}
	PostorderTraverse(node->left,action);
	PostorderTraverse(node->right,action);
	action(node->data);
}
void Delnode(btNode* node){
	if(node==NULL){
		return;
	}	
	Delnode(node->left);
	Delnode(node->right);
	free(node);
}
void DeleteTree(btNode* node){ //��Ʈ���� �������� ����. 
	if(node==NULL){
		return;
	}
	Delnode(node->left);
	Delnode(node->right);
	node->left=NULL;
	node->right=NULL; //������ NULL�Ҵ� 
}
