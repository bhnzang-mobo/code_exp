#ifndef __STACK__
#define __STACK__

typedef int SData;

typedef struct SNode{
	SData data;
	struct SNode* next;
}SNode;

typedef struct Stack{
	SNode* top;
	int count;
}Stack;
//functions
void Stackinit(Stack*);
void Push(Stack*,SData);
SData Pop(Stack*);
SData Peek(Stack*);

int isEmpty(Stack*);

#endif