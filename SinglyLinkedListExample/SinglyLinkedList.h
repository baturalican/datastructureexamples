#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

class Node;

class SinglyLinkedList
{
public:
	SinglyLinkedList();
	SinglyLinkedList(Node* node);
	~SinglyLinkedList();
	
	Node* isNodeFound(int key);
	void appendNode(Node* node);
	void prependNode(Node* node);
	void insertNodeAfter(int key, Node* node);
	void deleteNodeByKey(int key);
	void updateNodeByKey(int oldValue, int newValue);
	void printList();
private:
	Node* head {nullptr};
};

#endif // SINGLY_LINKED_LIST_H
