#include <stdio.h>
#include <malloc.h>
#include "stack.h"

void Stackinit(Stack* stack){
	stack->top=NULL;
	stack->count=0;
}
void Push(Stack* stack, SData data){
	SNode* newnode = (SNode*)malloc(sizeof(SNode));
	newnode->data=data;
	newnode->next=NULL;
	/* original
	if(!isEmpty(stack)){
		newnode->next=stack->top;
	}
	*/
	//modified
	newnode->next=stack->top;
	stack->top=newnode;
	stack->count+=1;
}

SData Pop(Stack* stack){
	if(!isEmpty(stack)){
		SNode * popnode = stack->top;
		SData ret = popnode->data;
		stack->top=stack->top->next;
		stack->count-=1;
		free(popnode);
		return ret;
	}
	else {
		printf("Stack Memory Error!\n");
		exit(-1);
	}
}

SData Peek(Stack* stack){
	if(!isEmpty(stack)){
		return stack->top->data;
	}
	else{
		printf("Stack Memory Error!\n");
		exit(-1);
	}
	
}

int isEmpty(Stack* stack){
	if(stack->top==NULL){
		return 1;
	}
	return 0;
}

