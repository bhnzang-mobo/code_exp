#include <stdio.h>

typedef int (fp)(int,int);

int main(){
	int add(int a, int b){
		return a+b;
	}
	fp *func = &add;
	printf("%d",func(1,3));
	return 0;
}
