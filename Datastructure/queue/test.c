#include "myqueue.h"
#include <stdio.h>

int main (){
	char c[3] = "MBH";
	Queue* a = createQueue(5);
	deQueue(a);
	enQueue(a,c);
	printf("%c",*deQueue(a));
	return 0;
}