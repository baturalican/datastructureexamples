#include <iostream>
#include "CircularQueue.h"

int main()
{
	CircularQueue myQueue(5);
	
	myQueue.dequeue();
	
	std::cout << "**********************************" << std::endl;
	
	myQueue.enqueue(5);
	myQueue.enqueue(3);
	myQueue.enqueue(12);
	myQueue.enqueue(7);
	myQueue.enqueue(2);
	myQueue.enqueue(78);
	
	std::cout << "**********************************" << std::endl;
	
	myQueue.dequeue();
	
	if(myQueue.isFull()) {
		std::cout << "The queue is full" << std::endl;
	} else {
		std::cout << "The queue is not full" << std::endl;
	}
	
	myQueue.display();
	
	std::cout << "**********************************" << std::endl;
	
	std::cout << "Number of elements in the queue is: " << myQueue.count() << std::endl;
	
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	
	myQueue.display();
	
	std::cout << "Number of elements in the queue is: " << myQueue.count() << std::endl;
	
	std::cout << "**********************************" << std::endl;
	
	return 0;
}
