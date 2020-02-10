#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//tiny declaration omit in header file.
//omit : used Node as node 
void queueinit(queue* queue){
	queue->count=0;
	queue->head = NULL;
	queue->tail = NULL;
}
void enqueue(queue* queue ,qdata data){
	node * newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	if(isQEmpty(queue)){
		queue->head=newnode;
	}
	else{
		queue->tail->next=newnode;
	}
	queue->tail=newnode;
	queue->count+=1;
}
qdata dequeue(queue* queue){
	if(!isQEmpty(queue)){
		qdata ret = queue->head->data;
		node* delnode = queue->head;
		queue->head=delnode->next;
		free(delnode);
		queue->count-=1;
		return ret;
	}
	else{
		printf("Queue memory Error!\n");
		exit(-1);
	}
}
qdata qpeek(queue* queue){
	if(!isQEmpty(queue)) return queue->head->data;
}
int isQEmpty(queue* queue){
	if(queue->count<=0){
		return 1;
	}
	else{
		return 0;
	}
}

