#ifndef __BINARY_TREE__
#define __BINARY_TREE__
typedef int btdata;

typedef struct btNode{
	btdata data;
	struct btNode* left;
	struct btNode* right;
}btNode;

typedef void (*VisitAction)(btdata);

btNode* MakeBTNode();
btdata GetData(btNode*);
void SetData(btNode*,btdata);

btNode* GetLeftSubTree(btNode*);
btNode* GetRightSubTree(btNode*);

void MakeLeftSubTree(btNode*,btNode*);
void MakeRightSubTree(btNode*,btNode*);

void PreorderTraverse(btNode*, VisitAction action);
void InorderTraverse(btNode*, VisitAction action);
void PostorderTraverse(btNode*, VisitAction action);

void DeleteTree(btNode*);
void Delnode(btNode*);
#endif