#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node();
	Node(int key, int data);
	~Node();
	
	int getKey();
	int getData();
	Node* getNextNode();
	void setKey(int key);
	void setData(int data);
	void setNextNode(Node* nextNode);
	
private:
	int key {0};
	int data {0};
	Node* next {nullptr};
};

#endif // NODE_H
