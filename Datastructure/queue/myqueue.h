typedef struct Queue {
	int capacity;
	int num;
	struct Queuenode* front, *rear;
}Queue;

typedef struct Queuenode {
	char* value;
	struct Queuenode* next;
}Queuenode;

Queue* createQueue(int);
void enQueue(Queue* , char*);
char* deQueue(Queue*);