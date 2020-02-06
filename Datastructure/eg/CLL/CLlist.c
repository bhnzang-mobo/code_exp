#include <stdio.h>
#include <stdlib.h>
#include "CLL.h"
//think tail, cur, before, count
//adding new node;
void Cinit(CList* cl){
	cl->tail=NULL;
	cl->cur=NULL;
	cl->before=NULL;
	cl->count=0; //원래 int count = 0; 이었음 레일 미침 이것때매 한 시간 소모함 ㅈ같은거 모보현 씨발년
}

void Cinsert(CList* cl,Data data){
	CNode* newnode = (CNode*)malloc(sizeof(CNode));
	newnode->data=data;

	if(cl->tail==NULL){
		cl->tail=newnode;
		cl->tail->next=newnode;
		cl->count+=1;
	}
	else{
		newnode->next=cl->tail->next;
		cl->tail->next=newnode;
		cl->tail=newnode;
		cl->count+=1;
	}

}

void CFinsert(CList* cl,Data data){
	CNode* newnode = (CNode*)malloc(sizeof(CNode));
	newnode->data=data;
	if(cl->tail==NULL){
		cl->tail=newnode;
		cl->tail->next=newnode;
	}
	else{
		newnode->next=cl->tail->next;
		cl->tail->next=newnode;
	}
	cl->count+=1;
}



//node reference;
int CFirst(CList* cl,CNode* node){
	if(cl->tail->next!=NULL){
		CNode * A=cl->tail->next;
		cl->cur=A;
		cl->before=cl->tail;
		*node=*A;
		return 1;
	}
	else{
		printf("Inappropriate approach\n");
		return 0;
	}
}

int CNext(CList* cl,CNode* node){
	if(cl->cur!=NULL){
		cl->before=cl->cur;
		cl->cur=cl->cur->next;
		*node=*(cl->cur);
		return 1;
	}
	else{
		printf("Inappropriate approach\n");
		return 0;
	}
}
Data CRemove(CList* cl){ //remove current node
	if(cl->cur!=NULL && cl->cur!=cl->before){
		if(cl->cur==cl->tail){
			cl->tail=cl->before;
		}
		CNode* delnode = cl->cur;
		Data ret = delnode->data;
		cl->before->next=delnode->next;
		cl->cur=cl->before;
		free(delnode);
		cl->count-=1;
		return ret;
	}
	else if(cl->cur!=NULL && cl->cur==cl->before){
		CNode* delnode = cl->cur;
		Data ret = delnode->data;
		cl->cur=NULL;
		cl->before=NULL;
		cl->count-=1;
		free(delnode);
		return ret;
	}
}
 

int CCount(CList* cl){
	return cl->count;
}