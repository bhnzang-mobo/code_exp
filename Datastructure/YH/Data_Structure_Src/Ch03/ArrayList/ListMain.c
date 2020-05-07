#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList의 생성 및 초기화 ***/
	List list;
	int data;
	int sum=0;
	ListInit(&list);
	for(int i = 1 ; i <= 9 ; i ++){
		LInsert(&list,i);
	}
	LFirst(&list,&data);
	sum+=data;
	for(int i = 1 ; i < 9 ; i ++){
		LNext(&list,&data);
		sum+=data;
	}
	printf("총 합은 %d 입니다.\n",sum);
	LFirst(&list,&data);
	for(int i = 0 ; i < 9 ; i ++){
		if(data%2==0 || data%3==0){
			LRemove(&list);
		}
		LNext(&list,&data);
	}
	LFirst(&list,&data);
	for(int i = 0 ; i < LCount(&list) ; i ++){
		printf("%d ",data);
		LNext(&list,&data);
	}
	return 0;
}