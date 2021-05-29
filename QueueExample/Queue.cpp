#include <iostream>
#include "Queue.h"

Queue::Queue(short queueSize) : size{queueSize}, front{-1}, rear{-1} {
	// Create a storage for elements on the heap
	this->elements = new int[queueSize];
	
	// Zeroize all the elements
	for (short i = 0; i < size; ++i) {
		elements[i] = 0;
	}
}

bool Queue::isFull() {
	// NOTE here that even if we dequeue one element and there is an empty spot in the queue we cannot access these area till we empty the queue
	// That's why, when the rear end hits the queue size - 1, the queue becomes full
	if (rear == size - 1) {
		return true;
	}
	
	return false;
}

bool Queue::isEmpty() {
	// Rear is -1 means that there is no enqueuing operation happened
	if (rear == -1) {
		return true;
	}
	
	return false;
}

int Queue::count() {
	if (isEmpty()) {
		return 0;
	}
	
	// We cannot apply rear - front + 1 when the queue is empty, cuz both values are -1 at that time and this formula gives us 1 which is wrong
	return rear - front + 1;
}

void Queue::enqueue(int element) {
	if (isFull()) {
		std::cout << "The queue is full, cannot insert the element!!!" << std::endl;
	}
	else if (isEmpty()) {
		front = 0;
		rear = 0;
		elements[rear] = element;
	} 
	// If the queue is NOT full and there is at least one element in the queue, we just insert the element and increase the rear end position
	else {
		elements[++rear] = element;
	}
}

int Queue::dequeue() {
	int element {0};
	if (isEmpty()) {
		std::cout << "The queue is empty, cannot remove the element!!!" << std::endl;
	}
	else {
		// When the queue is NOT empty, we guarantee the dequeue operation, so we just remove the first element from the front end and zeroize that position
		element = elements[front];
		elements[front] = 0;
		
		// If there is only one element in the queue, we just reset the front and the rear positions in the queue
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		
		// If there is more that one element in the queue, we just increase the front end position after removing the first from the front
		else {
			++front;
		}
	}
	
	return element;
}

void Queue::display() {
	for (short i = 0; i < size; ++i) {
		std::cout << elements[i] << " ";
	}
	
	std::cout << std::endl;
}

Queue::~Queue() {
	// Just freeing up the heap storage
	delete[] elements;
}



