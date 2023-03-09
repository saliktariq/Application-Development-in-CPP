#include <iostream>

using namespace std;

struct Node{
	
	int data;
	Node *next;
	Node *prev;
	Node(int d, Node *n, Node *p);
};

Node *head, *tail;
int cnt;

Node::Node(int d = 0, Node *n = NULL, Node *p = NULL){
		
		data = d;
		next = n;
		prev = p;
	}

void insertAtEnd(Node *n){
	if(tail != NULL){
		tail->next = n;
		n->prev = tail;
	}
	if(head == NULL) head = n;
	tail = n;
	cnt++;
}

Node* getNodeAt(int ind){
	if(ind >= 0 && ind < cnt){
		Node *temp = head;
		int i = 0;
		while(temp != NULL && i < ind){
			temp = temp->next;
			i++;
		}
		return temp;
	}
	return NULL;
}

void swapData(Node *n1, Node *n2){
	
	int temp = n1->data;
	n1->data = n2->data;
	n2->data = temp;
}

void shiftHeap(int cnt);
void heapRemove(int delInd, int cnt);



int main(){
	
	head = NULL;
	tail = head;
	cnt = 0;
	
	int ch, num;
	Node *n;
	do{
		cout << "\n1- add to heap\n2- delete from heap\n3- display heap\n4- Exit\n=";
		cin >> ch;
		switch(ch){
			case 1:
				cout << "\nEnter num = ";
				cin >> num;
				n = new Node(num);
				insertAtEnd(n);
				shiftHeap(cnt);
				break;
			case 2:
				cout << "\nEnter pos to delete = ";
				cin >> num;
				if(num < 0 || num >= cnt){
					cout << "\nInvalid position\n";
				}
				else{
					heapRemove(num, cnt);
					cnt--;
				}
				break;
			case 3:
				n = head;
				while(n != NULL){
					cout << n->data << "-->";
					n = n->next;
				}
				cout << endl;
				break;
			case 4:
				break;
			default:
				cout << "\nInvalid input\n";
				break;
		}
	}while(ch != 4);
}

void shiftHeap(int cnt){
	
	Node *curr = tail;
	for(int i = cnt-1; i > 0; i= (i-1)/2){
		Node *parent = getNodeAt((i-1)/2);
		if(curr->data < parent->data){
			int temp = curr->data;
			curr->data = parent->data;
			parent->data = temp;
		}
		curr = parent;
	}
	
}

void heapRemove(int delInd, int cnt){

	int i = delInd;
	Node *n = tail;
	Node *del = getNodeAt(i);
	//swap initial
	swapData(del, n);
	while(2*i+1 < cnt-1){
		//get nodes;
		Node *parent = getNodeAt(i);
		Node *leftchild = getNodeAt(2*i+1);
		Node *rightchild = (leftchild == NULL) ? NULL : leftchild->next;
		
		if(leftchild != NULL && rightchild != NULL){ // has 2 children
			if(parent->data > leftchild->data || parent->data > rightchild->data){
				if(leftchild->data < rightchild->data){
					if(leftchild != tail) swapData(parent, leftchild);
					i = 2*i+1;
				}
				else{
					if(rightchild != tail) swapData(parent, rightchild);
					i = 2*i+2;
				}
			}
		}
		else if(leftchild != NULL && parent->data > leftchild->data){ // only left child exists
			if(leftchild != tail) swapData(parent, leftchild);
			i = 2*i+1;
		}
		else{
			break;
		}
	}
	n = tail->prev;
	if(n != NULL){
		n->next = NULL;
	}
	delete tail;
	if(n == NULL){
		head = NULL;
		tail = NULL;
	}
	else{
		tail = n;
	}
}

