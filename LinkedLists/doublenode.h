class DoubleNode {
public:
	int data;
	DoubleNode* previous;
	DoubleNode* next;

	DoubleNode(int data) {
		this->data = data;
		previous = nullptr;
		next = nullptr;
	}
};
