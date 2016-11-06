#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

void init(Stack* s)
{
	s->top = 0;
	s->size = STACKSIZE;
	s->dane = (int*)malloc(sizeof(int)*STACKSIZE);
}

void destroy(Stack* s)
{
	free(s->dane);
}

void push(Stack* s, int element)
{
	s->dane[s->top++] = element;
	if(s->top == s->size)
	{
		s->dane = (int*)realloc(s->dane, (s->size*=2)*sizeof(int));
	}
}

int pop(Stack* s)
{
	assert(s->top > 0);
	return s->dane[--s->top];
}

void clear(Stack* s)
{
	s->top = 0;
}

bool isEmpty(Stack* s)
{
	return s->top > 0 ? false : true;
}
