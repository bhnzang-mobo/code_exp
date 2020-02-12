#include <stdio.h>
#include <malloc.h>
#include "deque.h"

void Dequeinit(deque* dq){
	dq->front=NULL;
	dq->rear=NULL;
	dq->count=0;
}

void Fenqueue(deque* dq,ddata data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=dq->front;
	
	if(dq->count<=0){
		dq->rear=newnode;
	}
	else{
		dq->front->prev=newnode;
	}
	dq->front=newnode;
	dq->count+=1;
}
void Renqueue(deque* dq,ddata data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=dq->rear;
	
	if(dq->count<=0){
		dq->front=newnode;
	}
	else{
		dq->rear->next=newnode;
	}
	dq->rear=newnode;
	dq->count+=1;
	
}
ddata Fdequeue(deque* dq){
	if(isDQEmpty(dq)){
		printf("Deque memory error!");
		exit(-1);
	}
	node * delnode = dq->front;
	ddata ret = delnode->data;
	dq->front=delnode->next;
	if(dq->front==NULL){
		dq->rear=NULL;
	}
	else{
		dq->front->prev=NULL;
	}
	free(delnode);
	dq->count-=1;
	return ret;
}
ddata Rdequeue(deque* dq){
	if(isDQEmpty(dq)){
		printf("Deque memory error!");
		exit(-1);
	}
	node * delnode = dq->rear;
	ddata ret = delnode->data;
	dq->rear=delnode->prev;
	if(dq->rear==NULL){
		dq->front=NULL;
	}
	else{
		dq->rear->next=NULL;
	}
	free(delnode);
	dq->count-=1;
	return ret;
}
ddata DQGetFirst(deque* dq){
	return dq->front->data;
}
ddata DQGetLast(deque* dq){
	return dq->rear->data;
}
int isDQEmpty(deque* dq){
	if(dq->count>=1) return 0;
	else return 1;
}
