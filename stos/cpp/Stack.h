#define STACKSIZE 20

class Stack
{
public:
	Stack();
	~Stack();
	void push(int element);
	int pop();
	void clear();
	bool isEmpty();
private:
	int top;
	int size;
	int* dane;
};
