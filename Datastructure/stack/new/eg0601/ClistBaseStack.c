#include <stdio.h>
#include <stdlib.h>
#include "ClistBaseStack.h"

int isEmpty(CList* cl){
	if(cl->count<=0) return 1;
	else return 0;
}
void Push(CList* cl,Data data){
	CFinsert(cl,data);
}
Data Pop(CList* cl){
	CNode node;
	if(CFirst(cl,&node)){
		CRemove(cl);
	}
	else{
		exit(-1);
	}
}
Data Peek(CList* cl){
	CNode node;
	if(CFirst(cl,&node)){
		return node.data;
	}
}

