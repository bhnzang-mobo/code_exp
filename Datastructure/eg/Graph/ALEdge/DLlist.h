#ifndef __D_Linked_List__
#define __D_Linked_List__
//strutcture
typedef int DData;

typedef struct DNode{
	DData data;
	struct DNode* left;
	struct DNode* right;
}DNode;

typedef struct DList{
	DNode* head;
	DNode* cur;
	DNode* tail;
	int count;
}DList;

//initiate
void Dinit(DList* dl);
//refer
int DFirst(DList*,DData*);
int DNext(DList*,DData*);
int DPrev(DList*,DData*);
int DCount(DList*);
//add
void Dinsert(DList*,DData);

//remove
DData DRemove(DList*);

#endif