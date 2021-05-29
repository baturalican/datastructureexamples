#ifndef STACK_H
#define STACK_H

class Stack
{
public:
	Stack(short size);
	~Stack();
	
	// Checks whether the stack is empty or not
	bool isEmpty();
	
	// Checks whether the stack is empty or not 
	bool isFull(); 
	
	// Return the number of elements on the stack
	int count();
	
	// Pushes an element to the stack
	void push(int);
	
	// Pops an element from the stack
	int pop();
	
	// Peeks the element at the provided location
	int peek(int);
	
	// Changes the element at the provided location
	void change(int, int);
	
	// Display all the elements on the stack
	void display();
	
private:
	int* elements;
	short size;
	int top;
};

#endif // STACK_H
