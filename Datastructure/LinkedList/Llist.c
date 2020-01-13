#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

void LLinit(LinkedList* LL){
	LL->count=0;
	LL->head=NULL;
	LL->tail=NULL;
}

//reference
void LLinsert(LinkedList * LL, LLData data){
	LLNode* node = (LLNode*)malloc(sizeof(LLNode));
	node->data=data;
	node->next=NULL;
	if(LL->head==NULL){ //first insert
		LL->head=node;
	}
	else LL->tail->next=node;
	LL->count+=1;
	LL->tail=node;
}

void LLhead(LinkedList * ll, LLNode* node){
	*node=*(ll->head);
}

void LLtail(LinkedList * ll, LLNode* node){
	*node=*(ll->tail);
}
void LLinfo(LinkedList* ll){
	printf("You have %dea\n",ll->count);
	LLNode* node = ll->head;
	if(ll->count>0){
	while(node!=NULL){
		printf("%d\n",node->data);
		node=node->next;
	}
	}
}
int LLremove(LinkedList* LL){
	LLNode* delnode = LL->head;
	LLNode* delnextnode = delnode->next;
	if(delnode==NULL){
		return 0;
	}

	while(delnode!=NULL){
		delnextnode=delnode->next;
		printf("delete %d.\n",delnode->data);
		free(delnode);
		delnode=delnextnode;
	}
	return 1;
}