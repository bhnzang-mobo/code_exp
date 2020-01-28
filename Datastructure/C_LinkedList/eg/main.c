#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLL.h"

int main () {
	CList cl;
	Data data;
	CNode node;
	Cinit(&cl);
	int num_emp;
	printf("Insert num of emp:");
	scanf("%d",&num_emp);
	char *name;
	for(int i = 0 ; i < num_emp; i ++){
		printf("Insert name\n");
		name=(char*)malloc(sizeof(char)*3);
		scanf("%s",name);
		Cinsert(&cl,name);
	}
	if(CFirst(&cl,&node)){
		printf("name? : \n");
		name=(char*)malloc(sizeof(char)*3);
		scanf("%s",name);
		printf("number? : \n");
		scanf("%d",&num_emp);
		while(strcmp(node.data,name)){
			CNext(&cl,&node);
		}
		for(int i = 0 ; i < num_emp ; i ++){
			CNext(&cl,&node);
		}
		printf("%s",node.data);
	}	
}
