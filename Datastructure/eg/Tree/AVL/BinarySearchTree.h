#ifndef __BINARYSEARCHTREE__
#define __BINARYSEARCHTREE__
#include "tree.h"
typedef btdata bstdata;

void BSTinit(btNode**);
btNode* BSTinsert(btNode**,bstdata);
bstdata BSTGetNodeData(btNode*);
btNode* BSTsearch(btNode**,bstdata);

btNode* BSTdelete(btNode**,bstdata);
bstdata BSTRemoveNode(btNode* pnode,btNode* node);

#endif