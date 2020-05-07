#include <stdio.h>
#include <stdlib.h>

#include "LL.h"

int main () {
	int cc(LLData d1, LLData d2){//정렬방식 선언
		if(d1->x>d2->x) return 1;
		else return 0;
	}
	LinkedList ll;
	LLNode node;
	LLinit(&ll);
	//데이터가 Pointer*자료형일경우
	SetSortRule(&ll,cc);//함수포인터 전달!
	for(int i = 0 ; i < 10 ; i ++){
		LLData data = (LLData)malloc(sizeof(Pointer));
		data->x=2*i;
		data->y=2*i+1;
		LLinsert(&ll,data);
	}
	/* //데이터가 int자료형일경우
	for(int i = 0 ; i < 10 ; i ++){
		LLinsert(&ll,i);
	}
	for(int i = 10 ; i < 20 ; i ++){
		LLinsert(&ll,i);
	}
	*/

	LLhead(&ll,&node);
	printf("Refer head. : %d\n",node.data);
	for(int i = 0 ; i < 10 ; i ++){ //Inappropriate approach expected.
		LLnext(&ll,&node);
		printf("now %d\n",node.data->x);
	}
	LLhead(&ll,&node);
	LLData del = LLremove(&ll);
	printf("Removed data : %d\n",del->x);
	LLData del2 = LLremove(&ll);
	LLnext(&ll,&node);
	printf("now %d\n",node.data->x);
	LLData del3 = LLremove(&ll);
	printf("Removed data : %d\n",del3->x);
	free(del);//사용자에서 malloc함.
	LLinfo(&ll);
	return 0;
}