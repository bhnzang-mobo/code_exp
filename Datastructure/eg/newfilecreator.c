#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
	char name [20]; //char*로 선언하고 문자열 받으면 안됨. char* a = "hello" 처럼
					//문자를 예약하면 안되고, 이 경우 읽기 전용이됨. 
	
	scanf("%s", name);
	while(strcmp(name,"0")){
		FILE* fptr = fopen(name,"w");
		fclose(fptr);
		scanf("%s", name);
	}
	
}
