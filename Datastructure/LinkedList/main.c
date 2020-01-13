#include <stdio.h>
#include <stdlib.h>

#include "LL.h"

int main () {
	LinkedList ll;
	LLNode node;
	LLinit(&ll);
	for(int i = 0 ; i < 10 ; i ++){
		LLinsert(&ll,i);
	}
	LLtail(&ll,&node);
	printf("%d\n",node.data);
	LLinfo(&ll);
	LLremove(&ll);
	return 0;
}