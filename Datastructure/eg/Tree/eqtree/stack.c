#include <stdio.h>
#include <malloc.h>
#include "stack.h"
#include <ctype.h>

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

void IntoPost(char* eq){
	int comp(char a, char b){
    int ak,bk;
    if(a=='+'||a=='-'){
        ak=0;
    }
    else{
        ak=1;
    }
    if(b=='+'||b=='-'){
        bk=0;
    }
    else{
        bk=1;
    }
    if(ak<bk){
        return 1;
    }
    else{
        return 0;
    }
}
	char ret[100];
	Stack stack;
	Stackinit(&stack);
	int i = 0;
    int j =0;
    char ch = eq[i];
    while(ch!='\0'){
        if(isdigit(ch)){
            ret[j++]=ch;
            ch=eq[++i];
        }
        else if(ch=='('){
            Push(&stack,ch);
            ch=eq[++i];
            continue;
        }
        else {
            if (ch == ')') {
                while (!isEmpty(&stack) && Peek(&stack) != '(') {
                    ret[j++] = Pop(&stack);
                }
                Pop(&stack);
                ch = eq[++i];
                continue;
            }
            while(!isEmpty(&stack)&&Peek(&stack)!='('&&!comp(Peek(&stack),ch)){
                ret[j++]=Pop(&stack);
            }
            Push(&stack, ch);
            ch = eq[++i];
        }
    }
    while(!isEmpty(&stack)){
        ret[j++]=Pop(&stack);
    }
    ret[j]='\0';
    i=0;
    ch=eq[0];
    while(eq[i]!='\0'){
    	eq[i]=ret[i++];
	}
}

