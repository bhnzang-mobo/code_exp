#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

void LLinit(LinkedList* LL){
	LL->count=0;
	LL->head=(LLNode*)malloc(sizeof(LLNode));
	LL->head->next=NULL;
	LL->tail=LL->head;
	LL->cur=LL->head;
	LL->before=NULL;
	LL->comp=NULL;
}

//reference
void LLinsert(LinkedList * LL, LLData data){
	LLNode* node = (LLNode*)malloc(sizeof(LLNode));
	node->data=data;
	node->next=NULL;

	/*if(LL->head==NULL){ //first insert
		LL->head=node;
	}*/
	//As we added dummy data, we could skip 'if' condition.
	if(LL->comp==NULL){ //Finsert
		node->next=LL->head->next;
		LL->head->next=node;
		LL->count+=1;
	}
	else{	//Sinsert
		LLNode* com = LL->head;
		int (*comp)(LLData,LLData)=LL->comp;
		while(com->next!=NULL && comp(data,com->next->data)==1){
			com=com->next;
		}
		node->next=com->next;
		com->next=node;
		LL->count+=1;
	}
}

void LLhead(LinkedList * ll, LLNode* node){
	*node=*(ll->head->next);
	ll->cur=ll->head->next;
	ll->before=ll->head;
}
/* No more use.
void LLtail(LinkedList * ll, LLNode* node){
	*node=*(ll->tail);
	ll->cur=ll->tail;
}
*/
void LLinfo(LinkedList* ll){
	printf("You have %dea\n",ll->count);
	LLNode* node = ll->head->next;
	if(ll->count>0){
	while(node!=NULL){
		printf("%d\n",node->data);
		node=node->next;
	}
	}
}
void LLnext(LinkedList* LL,LLNode* node){
	if(LL->cur->next!=NULL){
		*node=*(LL->cur->next);
		LL->before=LL->cur; //이게 없었어서 에러가 심했음
		LL->cur=LL->cur->next;
	}
	else{
	printf("Inappropriate approach.\n");
	}
}
//free & remove
LLData LLremove(LinkedList* LL){
	if(LL->before!=LL->cur){
		LLNode* delnode = LL->cur;
		LLData ret=delnode->data;
		LL->before->next=delnode->next;
		LL->cur=LL->before;
		LL->count-=1;
		free(delnode);
		return ret;
	}
	else{
		printf("Inappropriate approach.\n");
		return 0;
	}
}
int LLfree(LinkedList* LL){
	LLNode* delnode = LL->head->next;
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

void SetSortRule(LinkedList* LL, int(*comp)(LLData d1, LLData d2)){
	LL->comp=comp;
}