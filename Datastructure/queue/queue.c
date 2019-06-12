#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"

Queue* createQueue(int size) {
	Queue * newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->capacity = size;
	newQueue->front = NULL;
	newQueue->rear = NULL;
	newQueue->num = 0;
}

void enQueue(Queue* queue, char* value) {
	if (queue->rear ==NULL) {
		Queuenode* node = malloc(sizeof(Queuenode));
		node->value = value;
		node->next = NULL;
		queue->rear = node;
		queue->front = node;
		queue->num += 1;
		return;
	}
	Queuenode* prevNode = queue->rear;
	Queuenode* node = malloc(sizeof(Queuenode));
	node->value = value;
	node->next = NULL;
	prevNode->next = node;
	queue->rear = node;
	queue->num += 1;
	return;
}

char* deQueue(Queue* queue) {
	if (queue->num > 1) {
		Queuenode* node = queue->front;
		char* retValue = node->value;
		queue->front = node->next;
		free(node);
		queue->num--;
		return retValue;
	}
	else if (queue->num==1) {
		Queuenode* node = queue->front;
		char* retValue = node->value;
		queue->front = node->next;
		queue->rear = NULL;
		free(node);
		queue->num--;
		return retValue;
	}
	else {
		printf("Queue is empty.\n");
		return;
	}

}