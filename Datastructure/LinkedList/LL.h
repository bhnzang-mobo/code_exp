#ifndef __Llist_H__
#define __Llist_H__

typedef int LLData;

typedef struct LLNode{
	LLData data;
	struct LLNode * next;	
}LLNode;

typedef struct LinkedList{
	int count;
	LLNode* head;
	LLNode* tail;	
}LinkedList;

//initiation

void LLinit(LinkedList* );

//reference
void LLinsert(LinkedList * , LLData);
void LLhead(LinkedList*, LLNode*);
void LLtail(LinkedList*, LLNode*);
void LLinfo(LinkedList*);
//free & remove
int LLremove(LinkedList*);
#endif