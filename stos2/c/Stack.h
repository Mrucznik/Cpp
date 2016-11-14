#include <stdbool.h>

#define STACKSIZE 20

typedef struct Stack
{
	int top;
	int size;
	int* dane;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
void clear(Stack* s);
bool isEmpty(Stack* s);
