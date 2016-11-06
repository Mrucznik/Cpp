#include <assert.h>
#include <stdlib.h>
#include "Stack.h"

Stack::Stack()
{
	this->top = 0;
	this->size = STACKSIZE;
	this->dane = (int*)malloc(sizeof(int)*STACKSIZE);
}
	
Stack::~Stack()
{
	free(this->dane);
}

void Stack::push(int element)
{
	this->dane[this->top++] = element;
	if(this->top == this->size)
	{
		this->dane = (int*)realloc(this->dane, (this->size*=2)*sizeof(int));
	}
}

int Stack::pop()
{
	assert(this->top > 0);
	return this->dane[--this->top];
}

void Stack::clear()
{
	this->top = 0;
}

bool Stack::isEmpty()
{
	return this->top > 0 ? false : true;
}
