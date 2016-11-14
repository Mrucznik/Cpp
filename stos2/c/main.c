#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	init(s);
	
	//int error = pop(s); //test
	push(s, 10);
	push(s, 12);
	int e1, e2, p1, p2;
	e1 = pop(s);
	p1 = isEmpty(s);
	e2 = pop(s);
	p2 = isEmpty(s);
	printf("%d pusty: %d\n%d pusty: %d\n", e1, p1, e2, p2);
	
	for(int i=0; i<21; i++)
	{
		push(s, 4);
	}
	
	printf("size: %d\n", s->size);
	clear(s);
	printf("pusty: %d\n", isEmpty(s));
	
	destroy(s);
	free(s);
	return 0;
}
