#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
	Queue(short);
	~Queue();
	
	// Insert an element to the queue
	void enqueue(int);
	
	// Remove an element from the queue
	int dequeue();
	
	bool isFull();
	bool isEmpty();
	
	// Return the number of elements in the queue
	int count();
	
	void display();
	
private:
	short size;
	int* elements;
	short front;
	short rear;
};

#endif // QUEUE_H
