#include <stdio.h>
#include "tree.h"

void myaction(btdata data);

int main(){
	btNode* node[6];
	for(int i = 0 ; i < 6 ; i ++){
		node[i]=MakeBTNode();
	}
	for(int i = 0 ; i < 6 ; i ++){
		SetData(node[i],i+1);
	}
	MakeLeftSubTree(node[0],node[1]);
	MakeRightSubTree(node[0],node[2]);
	MakeLeftSubTree(node[1],node[3]);
	MakeRightSubTree(node[1],node[4]);
	MakeRightSubTree(node[2],node[5]);
	void myaction(btdata data){
		printf("%d ", data);
	}
	PreorderTraverse(node[0],myaction);
	printf("\n");
	InorderTraverse(node[0],myaction);
	printf("\n");
	PostorderTraverse(node[0],myaction);

}
