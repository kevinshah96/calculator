typedef struct token {
	int type;
	union data {
		int num;
		char op;
	}d;
}token;
typedef struct node {
	token a;
	struct node *next, *prev;
}node;
typedef struct queue {
	node *head, *tail;
}queue;
void qinit(queue *q);
void enqueue(queue *q, token *t);
token *dequeue(queue *q);
token *pop(queue *q);
int qempty(queue *q);
void printqueue(queue *q);
