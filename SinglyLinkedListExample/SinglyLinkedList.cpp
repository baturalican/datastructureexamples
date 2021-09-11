#include <iostream>
#include "SinglyLinkedList.h"
#include "Node.h"

SinglyLinkedList::SinglyLinkedList() : head{nullptr} {
}

SinglyLinkedList::SinglyLinkedList(Node* node) : head{node} {
	
}

SinglyLinkedList::~SinglyLinkedList() {
}

Node* SinglyLinkedList::isNodeFound(int key) {
	Node* temp = new Node;
	temp = nullptr;
	Node* ptr = head;
	
	// Travers through the entire linked list elements
	while(ptr != nullptr) {
		if (ptr->getKey() == key) {
			temp = ptr;
			return temp;
		}
		ptr = ptr->getNextNode();
	}
	
	return temp;
}

void SinglyLinkedList::appendNode(Node* node) {
	// If same node exists
	if (isNodeFound(node->getKey()) != nullptr) {
		std::cout << "Node already exists" << std::endl;
	} else {
		// If there is no node in the list
		if (head == nullptr) {
			head = node;
			std::cout << "Node appended" << std::endl;
			return;
		} else {
			Node* ptr = head;
			// Just go the end of the list
			while (ptr->getNextNode() != nullptr) {
				ptr = ptr->getNextNode();
			}
			
			ptr->setNextNode(node);
		}
	}
}

void SinglyLinkedList::prependNode(Node* node) {
	// If same node exists
	if (isNodeFound(node->getKey()) != nullptr) {
		std::cout << "Node already exists" << std::endl;
	} else {
		node->setNextNode(head);
		head = node;
		std::cout << "Node prepended" << std::endl;
		return;
	}
}

void SinglyLinkedList::insertNodeAfter(int key, Node* node) {
	Node* foundNode = nullptr;
	foundNode = isNodeFound(key);
	// Invalid key, no node found with the given key
	if (!foundNode) {
		std::cout << "No node found with the key of: " << key << std::endl;
		return;
	}
	
	// If same node exists
	if (foundNode->getKey() == node->getKey()) {
		std::cout << "Node is already on the list" << std::endl;
		return;
	}
	
	node->setNextNode(foundNode->getNextNode());
	foundNode->setNextNode(node);
	std::cout << "Node inserted" << std::endl;
	
}

void SinglyLinkedList::deleteNodeByKey(int key) {
	if (head == nullptr) {
		std::cout << "Linked list is already empty, cannot delete a node!" << std::endl;
		return;
	}
	
	// If head is to be deleted
	if (head->getKey() == key) {
		head = head->getNextNode();
		std::cout << "Node deleted" << std::endl;
		return;
	}
	
	// We have to keep previous element here so that when we delete the node, we could link the previous node to the next node
	Node* temp = nullptr;
	Node* previous = head;
	Node* current = head->getNextNode();
	
	while (current != nullptr) {
		// If you find the list element
		if (current->getKey() == key) {
			temp = current;
			current = nullptr;
			break;
		} else {
			previous = current;
			current = current->getNextNode();
		}
	}
	
	// If you find something to be deleted, delete it
	if (temp != nullptr) {
		previous->setNextNode(temp->getNextNode());
		std::cout << "Node deleted" << std::endl;
		return;
	}
	
	std::cout << "No node found with the key of: " << key << std::endl;
	
}

void SinglyLinkedList::updateNodeByKey(int key, int newValue) {
	Node* foundNode = isNodeFound(key);
	
	if (!foundNode) {
		std::cout << "No node found with a key of: " << key << std::endl;
		return;
	}
	
	foundNode->setData(newValue);
	std::cout << "Node updated successfully" << std::endl;
}

void SinglyLinkedList::printList() {
	if (head == nullptr) {
		std::cout << "There is no node in the list" << std::endl;
		return;
	}
	
	Node* temp = nullptr;
	temp = head;
	
	std::cout << "Linked list values: ";
	
	while (temp != nullptr) {
		std::cout << "(" <<  temp->getKey() << "," << temp->getData() << ")" << "--> ";
		temp = temp->getNextNode();
	}
	
	std::cout << "___" << std::endl;
}
