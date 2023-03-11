#include <iostream>

class SingleNode {
public:
	int data;
	SingleNode* next;

	SingleNode(int data) {
		this->data = data;
		next = nullptr;
	}
};
