typedef struct Stack_ele {
	char* value; //if you want to change type of value, change parameter of Push().
	struct Stack_ele* next; //self referential must to be like this "struct Stack_ele"
}Stack_ele;

typedef struct Stack {
	int size;
	int num_ele;
	struct Stack_ele* top;
}Stack;


void* CreateStack(int);
void DeleteEle(Stack_ele*);
void DeleteStack(Stack *);
int IsEmpty(Stack *);
void Push(Stack*, char*);
void Pop(Stack*);