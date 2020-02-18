#include "stack.h"
#include "tree.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

btNode* MakeExpressTree(char* eq){
	Stack stack;
	Stackinit(&stack);
	int i = 0 ;
	while(eq[i]!='\0'){
		btNode* node = MakeBTNode();
		if(isdigit(eq[i])){
			SetData(node,eq[i]-'0');//if eq[i] is number
		}
		else{ //else, eq[i] is operator
			MakeRightSubTree(node,Pop(&stack));
			MakeLeftSubTree(node,Pop(&stack));
			SetData(node,eq[i]);
		}
		Push(&stack,node);
		i++;
	}
	return Pop(&stack);
}

int EvalExpTree(btNode* node){
	if(node->left==NULL){
		return node->data;
	}
	switch(node->data){
		case '+': {
			return EvalExpTree(node->left)+EvalExpTree(node->right);
			break;
		}
		case '-' :{
			return EvalExpTree(node->left)-EvalExpTree(node->right);
			break;
		}
		case '/' :{
			return EvalExpTree(node->left)/EvalExpTree(node->right);
			break;
		}
		case '*':{
			return EvalExpTree(node->left)*EvalExpTree(node->right);
			break;
		}
	}
}
void ShowNode(btdata data){
	if(0<=data && data<=9){
		printf("%d ",data);
	}
	else{
		printf("%c ", data);//segmentation fault occurs when "%s"

	}
}

void ShowPrefixExp(btNode* node){
	PreorderTraverse(node,ShowNode);
}
void ShowInfixExp(btNode* node){
	if(node->left==NULL){
		ShowNode(node->data);
		return;
	}
	printf("(");
	ShowInfixExp(node->left);
	ShowNode(node->data);
	ShowInfixExp(node->right);
	printf(")");
}
void ShowPostfixExp(btNode* node){
	PostorderTraverse(node,ShowNode);
}






