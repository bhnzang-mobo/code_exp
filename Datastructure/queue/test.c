#include "myqueue.h"
#include <stdio.h>

int main (){
	char data;
	int num;
	scanf("%d",&num);
	Queue* a = createQueue(num);
	Queuenode * node;
	for(int i = 0 ; i < num+1 ; i ++){
		enQueue(a,'A');
	}
	node=getQFront(a);
	printf("%d\n",num);
	for(int i = 0 ; i < 10 ; i ++){
		printf("%c\n",deQueue(a));
	}
	return 0;
}