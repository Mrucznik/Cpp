#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
	int opcja=0, k;
	Stack s;
	init(&s);
	do
	{
		fseek(stdin, 0, SEEK_END);
		fflush(stdin);
		getchar();
		printf("Opcje:\n1-push\n2-pop\n3-clear\n4-isEmpty\n: ");
		k = scanf("%d", &opcja);
	} while(k != 1 || (opcja < 1 || opcja > 4));


/*	do
	{
		printf("Opcje:\n1-push\n2-pop\n3-clear\n4-isEmpty\n: ");
		scanf("%d", &opcja);
	
		switch(opcja)
		{
			case 1:
				int arg;
				scanf("%d", &arg);
				push(&s, sarg);
				break;
			case 2:
				printf("pop: %d", pop(&s));
				break;
			case 3:
				printf("stack clear");
				break;
			case 4:
				printf("Empty: %s");
				break;
			default:
				printf("Zla opcja!");
				break;
		}
	} while(opcja >= 1 && opcja <= 4);
	
	
	
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
	free(s);*/
	return 0;
}
