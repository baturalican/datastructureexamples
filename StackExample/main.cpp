#include <iostream>
#include "Stack.h"

int main()
{
	Stack myStack(5);
	
	myStack.pop();
	
	myStack.push(3);
	myStack.push(2);
	myStack.push(1);
	myStack.push(4);
	myStack.push(5);
	myStack.push(6);
	
	myStack.pop();
	myStack.pop();
	
	myStack.push(6);
	
	std::cout << "Bottom element is: " << myStack.peek(0) << std::endl;
	
	myStack.display();
	
	myStack.change(0, 21);
	
	myStack.display();
	
	return 0;
}
