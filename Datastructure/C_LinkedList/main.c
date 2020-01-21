#include <stdio.h>
#include <stdlib.h>
#include "CLL.h"

int main () {
	CList cl;
	Data data;
	CNode node;
	Cinit(&cl);
	
	Cinsert(&cl,3);
	Cinsert(&cl,4);
	Cinsert(&cl,5);
	CFinsert(&cl,2);
	CFinsert(&cl,1);
	
	int nodnum = CCount(&cl);
	
	if(CFirst(&cl,&node)){
		printf("%d ",node.data);
		for(int i = 0 ; i < nodnum*3-1; i++){
			CNext(&cl,&node);
			printf("%d ",node.data);
		}
	}
	printf("\n");
	if(nodnum!=0){
		CFirst(&cl,&node);
		if(node.data%2 == 0){
			CRemove(&cl);
		}

		for(int j = 0 ; j < 4; j ++){
			CNext(&cl,&node);
			if(node.data%2 == 0){
				CRemove(&cl);
			}
		}
	}
	if(CFirst(&cl,&node)){
		printf("%d ",node.data);
		for(int i = 0 ; i < CCount(&cl)-1; i++){
			CNext(&cl,&node);
			printf("%d ",node.data);
		}
	}
}
