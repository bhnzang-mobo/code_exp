#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"

void initQueue(Queue* newQueue,int size) {
	newQueue->capacity = size;
	newQueue->front = NULL;
	newQueue->rear = NULL;
	newQueue->num = 0;
}

void enQueue(Queue* queue, QData value) {
	if (queue->rear ==NULL) {
		Queuenode* node = malloc(sizeof(Queuenode));
		node->value = value;
		node->next = NULL;
		queue->rear = node;
		queue->front = node;
		queue->num += 1;
		return;
	}
	if(queue->capacity > queue->num){
	Queuenode* prevNode = queue->rear;
	Queuenode* node = malloc(sizeof(Queuenode));
	node->value = value;
	node->next = NULL;
	prevNode->next = node;
	queue->rear = node;
	queue->num += 1;
	return;
	}
}

QData deQueue(Queue* queue) {
	if (queue->num > 1) {
		Queuenode* node = queue->front;
		QData retValue = node->value;
		queue->front = node->next;
		free(node);
		queue->num--;
		return retValue;
	}
	if (queue->num==1) {
		Queuenode* node = queue->front;
		QData retValue = node->value;
		queue->front = node->next;
		queue->rear = NULL;
		free(node);
		queue->num--;
		return retValue;
	}
	printf("Queue is empty\n");
}
void freeQueue(Queue* queue){
	for(int i = 0 ; i < queue->num ; i ++){
		deQueue(queue);
	}	
}

Queuenode* getQFront(Queue* queue){
	return queue->front;
}

Queuenode* getQRear(Queue* queue){
	return queue->rear;
}

int isFull(Queue queue){
	if(queue.num>=queue.capacity){
	printf("Queue is Full\n");
	return 1;
}
	else{
	return 0;
}
}

int isEmpty(Queue queue){
	if(queue.num<=0){
	printf("Queue is Empty\n");
	return 1;
	}
	else{
	return 0;
	}
}