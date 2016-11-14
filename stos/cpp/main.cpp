#include <stdio.h>
#include "Stack.h"

using namespace std;

int main()
{
	int opcja=0;
	Stack s = Stack();
	do
	{
		printf("\nOpcje:\n1-push\n2-pop\n3-clear\n4-isEmpty\n: ");
		scanf("%d", &opcja);
	
		int arg;
		switch(opcja)
		{
			case 1:
				scanf("%d", &arg);
				s.push(arg);
				printf("push: %d", arg);
				break;
			case 2:
				printf("pop: %d", s.pop());
				break;
			case 3:
				printf("stack clear");
				s.clear();
				break;
			case 4:
				printf("Empty: %s", s.isEmpty() ? "Tak" : "Nie");
				break;
			default:
				printf("Zla opcja!");
				break;
		}
		getchar();
		getchar();
	} while(opcja >= 1 && opcja <= 4);
	return 0;
}
