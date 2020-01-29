#include <stdio.h>
#include "DLlist.h"

int main(){
	DList list;
	int data;
	Dinit(&list);
	for(int i = 1; i < 9 ; i ++){
		Dinsert(&list,i);
	}
	if(DFirst(&list,&data)){
		printf("%d ", data);
		while(DNext(&list,&data)){
			printf("%d ",data);
		}
	}
	if(DFirst(&list,&data)){
		if(data%2==0){
			DRemove(&list);
		}
		while(DNext(&list,&data)){
			if(data%2==0){
			DRemove(&list);
		}
		}
	}
	printf("\n");
	if(DFirst(&list,&data)){
		printf("%d ", data);
		while(DNext(&list,&data)){
			printf("%d ",data);
		}

	}
	printf("\n%d",DCount(&list));
	return 0;
}
