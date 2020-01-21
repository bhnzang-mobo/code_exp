#ifndef __C_Llist_H__
#define __C_Llist_H__

typedef int Data;
typedef struct Cnode{
	Data data;
	struct Cnode* next;
}CNode;

typedef struct Clist{
	CNode* tail;
	CNode* cur;
	CNode* before;
	int count;
}CList;

//adding new node;
void Cinit(CList*);
void Cinsert(CList*,Data);	//insert data on head
void CFinsert(CList*,Data);	//insert data on tail
//node reference;
int CFirst(CList*,CNode*);
int CNext(CList*,CNode*);
Data CRemove(CList*);
int CCount(CList*);
#endif