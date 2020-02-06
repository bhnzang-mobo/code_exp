#include <stdio.h>
#include "ClistBaseStack.h"

int main(){
	CList stack;
	Cinit(&stack);
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
