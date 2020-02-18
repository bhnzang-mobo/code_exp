#ifndef __EX__
#define __EX__

#include "tree.h"

btNode* MakeExpressTree(char*);
int EvalExpTree(btNode*);

void ShowPrefixExp(btNode*);
void ShowInfixExp(btNode*);
void ShowPostfixExp(btNode*);


#endif