#include <iostream>
#include "Stack.h"

Stack::Stack(short stackSize) : size{stackSize}{
	// Create a storage on the heap
	this->elements = new int[stackSize];
	
	// First we initialize all the elements on the stack to 0
	for (short i = 0; i < stackSize; ++i) {
		elements[i] = 0;
	}
}

Stack::~Stack(){
	delete[] elements;
}

bool Stack::isEmpty() {
	// If no element is inserted then the stack is empty, not empty otherwise
	if (top == -1) {
		return true;
	}
	
	return false;
}

bool Stack::isFull() {
	// If the number of elements on the stack is equal to the size (i.e. top element location is 1 less than the stack size) stack is full, not full otherwise
	if (top == size - 1) {
		return true;
	}
	
	return false;
}

int Stack::count() {
	return top + 1;
}

void Stack::push(int element) {
	// If the stack is full we cannot push the element to the stack, we can otherwise.
	if (isFull()) {
		std::cout << "The stack is full, cannot insert the element" << std::endl;
		return;
	}
	
	elements[++top] = element;
}

int Stack::pop() {
	// If the stack is empty we cannot pop the top element from the stack, we can otherwise.
	if (isEmpty()) {
		std::cout << "The stack is empty, cannot pop an element" << std::endl;
		return 0;
	}
	
	int topElement = elements[top];
	
	// After getting top element, we have to zeroize the top element
	elements[top] = 0;
	--top;
	return topElement;
}

int Stack::peek(int position) {
	return elements[position];
}

void Stack::change(int position, int value) {
	if (isEmpty()) {
		std::cout << "The stack is empty" << std::endl;
		return;
	}
	
	elements[position] = value;
}

void Stack::display() {
	std::cout << "*****************" << std::endl;

	for (short i = size - 1; i >= 0; --i) {
		std::cout << elements[i] << std::endl;
	}
}





