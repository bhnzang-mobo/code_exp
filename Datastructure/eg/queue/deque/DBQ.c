#include "DequeBaseQueue.h"
#include <stdio.h>

int main(){
	deque dq;
	Queueinit(&dq);
	for(int i = 0 ; i < 10 ; i++){
		Enqueue(&dq,i);
	}
	while(!isQEmpty(&dq)){
		printf("%d ",Dequeue(&dq));
	}
	return 0;
}
