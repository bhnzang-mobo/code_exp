#include "myqueue.h"
#include <stdio.h>

int main (){
	char data;
	int num;
	scanf("%d",&num);
	Queue a;
	initQueue(&a,num);
	Queuenode * node;
	for(int i = 0 ; i < num+1 ; i ++){
		if(isFull(a)==0){	
			enQueue(&a,'A');
		}
	}
	node=getQFront(&a);
	printf("%d\n",num);
	for(int i = 0 ; i < num+1 ; i ++){
		if(isEmpty(a)==0){
			printf("%c\n",deQueue(&a));
		}
	}
	return 0;
}