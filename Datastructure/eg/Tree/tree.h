#ifndef __BINARY_TREE__
#define __BINARY_TREE_
typedef int btdata;

typedef struct btNode{
	btdata data;
	struct btNode* left;
	struct btNode* right;
}btNode;

btNode* MakeBTNode();
btdata GetData(btNode*);
void SetData(btNode*,btdata);

btNode* GetLeftSubTree(btNode*);
btNode* GetRightSubTree(btNode*);

void MakeLeftSubTree(btNode*,btNode*);
void MakeRightSubTree(btNode*,btNode*);


#endif