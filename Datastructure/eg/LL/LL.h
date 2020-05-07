#ifndef __Llist_H__
#define __Llist_H__

typedef struct Pointer{
	int x;
	int y;
}Pointer;

typedef Pointer* LLData;

typedef struct LLNode{
	LLData data;
	struct LLNode * next;	
}LLNode;

typedef struct LinkedList{
	int count; //a.k.a numOfData
	LLNode* head;
	LLNode* tail;
	LLNode* before;
	LLNode* cur;
	int (*comp)(LLData d1, LLData d2);	
}LinkedList;

//initiation

void LLinit(LinkedList* );

//reference
/*void LLtail(LinkedList*, LLNode*);*/

void LLinsert(LinkedList * , LLData);
void LLhead(LinkedList*, LLNode*);
void LLinfo(LinkedList*);
void LLnext(LinkedList*,LLNode*);
//free & remove
LLData LLremove(LinkedList*);//remove current node;
int LLfree(LinkedList*);
//sort
void SetSortRule(LinkedList * LL, int (*comp)(LLData d1,LLData d2));
#endif