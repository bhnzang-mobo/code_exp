#include <stdio.h>
#include "tree.h"

int main(){
	btNode* node = MakeBTNode();
	btNode* newnode = MakeBTNode();
	SetData(newnode,2);
	MakeLeftSubTree(node,newnode);
	SetData(node,1);
	
	printf("%d ", GetData(GetLeftSubTree(node)));
}
