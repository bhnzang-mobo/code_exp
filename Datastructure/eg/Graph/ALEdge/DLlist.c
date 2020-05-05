#include <stdio.h>
#include "DLlist.h"
#include <malloc.h>
//Don't miss malloc
//Be carefull about the data type (e.g. *data = *(dl->cur->data) <- this is what i had done)
//When i declare insert funtion, i missed special case, which was the time when the head node is NULL
//I thought insertion could be done without exceptional case.
void Dinit(DList* dl){
	dl->count=0;
	DNode* hdmy = (DNode*)malloc(sizeof(DNode));
	hdmy->left=NULL;

	DNode* tdmy = (DNode*)malloc(sizeof(DNode));
	tdmy->right=NULL;

	hdmy->right=tdmy;
	tdmy->left=hdmy;
	dl->head=hdmy;
	dl->tail=tdmy;
}

int DFirst(DList* dl, DData* data){
	if(dl->head->right==dl->tail){ //remove할경우 head->right ==NULL 이 안먹힘.
						/* 이경우 head==tail 인지로 구분.*/
		return 0;
	}
	else{
		dl->cur=dl->head->right;
		*data=dl->cur->data;
		return 1;
	}
}

int DNext(DList* dl, DData* data){
	if(dl->cur->right!=dl->tail){
		dl->cur=dl->cur->right;
		*data=dl->cur->data;
		return 1;
	}
	else{
		return 0;
	}
}

int DPrev(DList* dl, DData* data){
	if(dl->cur->left!=dl->head){
		dl->cur=dl->cur->left;
		*data=dl->cur->data;
		return 1;
	}
	else{
		return 0;
	}
}

int DCount(DList* dl){
	return dl->count;
}

void Dinsert(DList* dl, DData data){
	DNode* newnode=(DNode*)malloc(sizeof(DNode));
	newnode->data=data;
	newnode->right=dl->tail;
	newnode->left=dl->tail->left;
	newnode->left->right=newnode;
	dl->tail->left=newnode;
	dl->count+=1;
}

DData DRemove(DList* dl){
	DNode* delnode = dl->cur;
	DData ret = delnode->data;
	delnode->left->right=delnode->right;
	delnode->right->left=delnode->left;
	dl->cur=delnode->left;
	free(delnode);
	dl->count-=1;
	return ret;
}
