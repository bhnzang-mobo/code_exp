#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
	char name [20]; //char*�� �����ϰ� ���ڿ� ������ �ȵ�. char* a = "hello" ó��
					//���ڸ� �����ϸ� �ȵǰ�, �� ��� �б� �����̵�. 
	
	scanf("%s", name);
	while(strcmp(name,"0")){
		FILE* fptr = fopen(name,"w");
		fclose(fptr);
		scanf("%s", name);
	}
	
}
