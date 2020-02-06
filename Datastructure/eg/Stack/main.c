#include <stdio.h>
#include "stack.h"

int main(){
	Stack stack;
	Stackinit(&stack);
	for(int i = 1 ; i <= 5 ; i ++){
		Push(&stack,i);
	}
	printf("%d ",Peek(&stack));	
	while(!isEmpty(&stack)){
		printf("%d ",Pop(&stack));
	}
	printf("%d",isEmpty(&stack));
	return 0;
}
