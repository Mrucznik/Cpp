#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack s = Stack();
	
	//int error = s.pop(); //test
	s.push(10);
	s.push(12);
	int e1, e2, p1, p2;
	e1 = s.pop();
	p1 = s.isEmpty();
	e2 = s.pop();
	p2 = s.isEmpty();
	cout << e1 << " pusty: " << p1 << endl << e2 << " pusty: " << p2 << endl;
		
	for(int i=0; i<21; i++)
	{
		s.push(4);
	}
	
	s.clear();
	cout << "pusty: " << s.isEmpty() << endl;
	return 0;
}
