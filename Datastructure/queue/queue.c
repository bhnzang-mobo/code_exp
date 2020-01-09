#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"

Queue* createQueue(int size) {
	Queue * newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->capacity = size;
	newQueue->front = NULL;
	newQueue->rear = NULL;
	newQueue->num = 0;
	return newQueue;
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
	printf("Queue is Full\n");
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
