#include <stdio.h>
#include "DequeBaseQueue.h"

void Queueinit(deque* dq){
	Dequeinit(dq);
}
int isQEmpty(deque* dq){
	return isDQEmpty(dq);
}
void Enqueue(deque* dq, ddata data){
	Renqueue(dq,data);
}
ddata Dequeue(deque* dq){
	return Fdequeue(dq);
}
ddata Peek(deque* dq){
	return DQGetFirst(dq);
}
