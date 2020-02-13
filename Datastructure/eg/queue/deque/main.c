#include "deque.h"
#include <stdio.h>

int main(){
	deque dq;
	Dequeinit(&dq);
	for(int i = 3 ; i > 0 ; i --){
		Fenqueue(&dq,i);
	}
	for(int i = 4 ; i <= 6 ; i ++){
		Renqueue(&dq,i);
	}
	while(!isDQEmpty(&dq)){
		printf("%d ",Fdequeue(&dq));
	}
	
	for(int i = 3 ; i > 0 ; i --){
		Fenqueue(&dq,i);
	}
	for(int i = 4 ; i <= 6 ; i ++){
		Renqueue(&dq,i);
	}
	while(!isDQEmpty(&dq)){
		printf("%d ",Rdequeue(&dq));
	}
	return 0;
}
