#include <iostream>
#include "CircularQueue.h"

CircularQueue::CircularQueue(short queueSize) : size{queueSize}, front{-1}, rear{-1}, elementCount{0} {
	// Create a storage for elements on the heap
	this->elements = new int[queueSize];
	
	// Zeroize all the elements
	for (short i = 0; i < size; ++i) {
		elements[i] = 0;
	}
}

bool CircularQueue::isFull() {
	// We check here that if the rear is one position behind the front position when we use modulo operator (since it is circular queue), then it means the queue is full
	if ((rear + 1) % size == front) {
		return true;
	}
	
	return false;
}

bool CircularQueue::isEmpty() {
	// Rear is -1 means that there is no enqueuing operation happened
	if (rear == -1) {
		return true;
	}
	
	return false;
}

int CircularQueue::count() {
	return elementCount;
}

void CircularQueue::enqueue(int element) {
	if (isFull()) {
		std::cout << "The queue is full, cannot insert the element!!!" << std::endl;
		return;
	}
	else if (isEmpty()) {
		front = 0;
		rear = 0;
		elements[rear] = element;
	} 
	// If the queue is NOT full and there is at least one element in the queue, we just insert the element and increase the rear end position
	else {
		rear = (rear + 1) % size;
		elements[rear] = element;
	}
	
	++elementCount;
}

int CircularQueue::dequeue() {
	int element {0};
	if (isEmpty()) {
		std::cout << "The queue is empty, cannot remove the element!!!" << std::endl;
	}
	else {
		// When the queue is NOT empty, we guarantee the dequeue operation, so we just remove the first element from the front end and zeroize that position
		element = elements[front];
		elements[front] = 0;
		--elementCount;
		
		// If there is only one element in the queue, we just reset the front and the rear positions in the queue
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		
		// If there is more than one element in the queue, we just increase the front end position 
		// (Since it is a circular queue, we have to include modulo operation after increasing front position by one)
		else {
			front = (front + 1) % size;
		}
	}
	
	return element;
}

void CircularQueue::display() {
	for (short i = 0; i < size; ++i) {
		std::cout << elements[i] << " ";
	}
	
	std::cout << std::endl;
}

CircularQueue::~CircularQueue() {
	// Just freeing up the heap storage
	delete[] elements;
}



