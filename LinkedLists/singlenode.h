#ifndef SINGLENODE_H
#define SINGLENODE_H

class SingleNode {
public:
	int data;
	SingleNode* next;

	SingleNode(int data) {
		this->data = data;
		next = nullptr;
	}
};
#endif