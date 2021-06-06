#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

class CircularQueue
{
public:
	CircularQueue(short);
	~CircularQueue();
	
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
	short elementCount;
};

#endif // CIRCULAR_QUEUE_H
