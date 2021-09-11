#include "Node.h"

Node::Node() : key{0}, data{0}, next{nullptr} {

}

Node::Node(int k, int d) : key{k}, data{d} {
	
}

Node::~Node() {
}

int Node::getKey() {
	return key;
}

int Node::getData() {
	return data;
}

Node* Node::getNextNode() {
	return next;
}

void Node::setKey(int key) {
	this->key = key;
}

void Node::setData(int data) {
	this->data = data;
}
	
void Node::setNextNode(Node* nextNode) {
	this->next = nextNode;
}
