#include <iostream>
#include "SinglyLinkedList.h"
#include "Node.h"

int main()
{
	SinglyLinkedList myLinkedList;
	
	std::cout << "**********Print the empty list**********" << std::endl;
	
	myLinkedList.printList();
	
	std::cout << "\n**********Insert a head node(1, 10)**********" << std::endl;
	
	Node headNode{1, 10};
	myLinkedList.appendNode(&headNode);
	
	myLinkedList.printList();
	
	std::cout << "\n**********Prepend another node(2, 20) and change the head node**********" << std::endl;
	
	Node myOtherHeadNode{2,20};
	myLinkedList.prependNode(&myOtherHeadNode);
	
	myLinkedList.printList();
	
	std::cout << "\n**********Insert couple of nodes**********" << std::endl;
	
	Node n1{3, 30};
	Node n2{4, 40};
	Node n3{5, 50};
	
	myLinkedList.appendNode(&n1);
	myLinkedList.appendNode(&n2);
	myLinkedList.appendNode(&n3);
	
	myLinkedList.printList();
	
	std::cout << "\n**********Delete a middle node(4, 40)**********" << std::endl;
	
	myLinkedList.deleteNodeByKey(4);
	
	myLinkedList.printList();
	
	std::cout << "\n**********Insert a node(6, 60) after a node(3, 30)**********" << std::endl;
	
	Node n4{6, 60};
	
	myLinkedList.insertNodeAfter(3, &n4);
	
	myLinkedList.printList();
	
	std::cout << "\n**********Update a node(5, 50)'s value to 100 **********" << std::endl;
	
	myLinkedList.updateNodeByKey(5, 100);
	
	myLinkedList.printList();
	
	return 0;
}
