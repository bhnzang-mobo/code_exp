#ifndef __BINARYSEARCHTREE__
#define __BINARYSEARCHTREE__
#include "tree.h"
typedef btdata bstdata;

void BSTinit(btNode**);
void BSTinsert(btNode**,bstdata);
bstdata BSTGetNodeData(btNode*);
btNode* BSTsearch(btNode*,bstdata);

void BSTdelete(btNode**,bstdata);
bstdata BSTRemoveNode(btNode* pnode,btNode* node);


#endif