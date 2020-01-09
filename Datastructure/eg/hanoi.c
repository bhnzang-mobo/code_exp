#include <stdio.h>
#include <math.h>

void hanoi(int num, int from, int by, int to){
	if(num==1){
	printf("%d %d\n",from,to);
	return;
	}
	hanoi(num-1,from,to,by);
	printf("%d %d\n",from,to);
	hanoi(num-1,by,from,to);
}

int main(){
    int num;
    scanf("%d",&num);
    printf("%d \n",(int)pow(2,num)-1);
	hanoi(num,1,2,3);
	return 0;
}