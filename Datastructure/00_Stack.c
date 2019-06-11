#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_ele {
	char* value; //if you want to change type of value, change parameter of Push().
	struct Stack_ele* next; //self referential must to be like this "struct Stack_ele"
}Stack_ele;

typedef struct Stack{
	int size;
	int num_ele;
	struct Stack_ele* top;
}Stack;


void* CreateStack(int size) {
	if (size <= 0) {
		printf("Enter valid size.\n");
		return 0;
	}
	else {
		Stack * a = malloc(sizeof(Stack));
		a->size = size;
		a->num_ele = 0;
		a->top = NULL;
		return a;
	}
}


void DeleteEle(Stack_ele* ele) {
	if (ele->next != NULL) {
		DeleteEle(ele->next);
		printf("memory freed\n");
		free(ele);
	}
	else {
		printf("memory freed\n");
		free(ele);
	}
}

void DeleteStack(Stack * address) {
	DeleteEle(address->top);
	printf("memory freed\n");
	free(address);
}


int IsEmpty(Stack * a) {
	if (a->num_ele == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void Push(Stack* a, char* value) {
	if (a->size > a->num_ele) {
		a->num_ele++;
		Stack_ele* node_tmp = a->top;
		a->top = malloc(sizeof(Stack_ele));
		a->top->value = value;
		a->top->next = node_tmp;
	}
	else {
		printf("Stack Overflow\n");
		return ;
	}
}

void Pop(Stack * a) {
	if(a->num_ele <= 0){
		printf("There is no Element to be popped.\n");
	}
	else {
		printf("%d,pop\n", a->top->value);
		Stack_ele * node = a->top;
		a->top = node->next;
		free(node);
		a->num_ele--;
	}
}

int main() {
	Stack * a = CreateStack(7);
	for (int i = 1; i < 9; i++) {
		Push(a, i);
	}
	return 0;
}