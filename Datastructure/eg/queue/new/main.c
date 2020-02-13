#include <stdio.h>
#include "queue.h"

int main (){
	queue que;
	queueinit(&que);
	for(int i = 0 ; i < 6 ; i ++){
		enqueue(&que,i);
	}
	printf("\nfront : %d\n",qpeek(&que));
	while(!isQEmpty(&que)){
		printf("%d ",dequeue(&que));
	}
	
	return 0;
}
