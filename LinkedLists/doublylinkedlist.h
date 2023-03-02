#include <iostream>
using namespace std;

struct Node {
	struct Node *prev;
	int data;
	struct Node *next;
};

Node *head = NULL;
int count = 0;

int listSize(){
	return count;
}

void insertEnd(int element){
	Node *tempNode = new Node();
	tempNode->data = element;
	tempNode->next = NULL;
	tempNode->prev = NULL;
	
	if(head == NULL){
		head = tempNode;
	} else {
		Node *lastNode = head;
		while(lastNode->next != NULL){
			lastNode = lastNode->next;
		}
		lastNode->next = tempNode;
		tempNode->prev = lastNode;
	}
	count++;
}

void insertBegin(int element){
	Node *tempNode = new Node();
	tempNode->data = element;
	tempNode->next = NULL;
	tempNode->prev = NULL;
	
	if(head == NULL){
		head = tempNode;
	} else {
		Node *previousHead = head;
		head = tempNode;
		head->next = previousHead;
		previousHead->prev = head;
	}
	count++;
}

void displayList(){
	if(listSize()==0){
		cout <<"List Empty\n";
	} else {
		cout <<"List Elements are: \n";
		for(Node *p = head; p!=NULL; p=p->next){
			cout<<"------------------------------"<<endl;
			if(p->prev == NULL){
				cout<<"Previous: NULL"<<endl;
			} else {
				cout<<"Previous: " << p->prev->data<<endl;
			}
			cout<<"Data: " << p->data<<endl;
			if(p->next == NULL){
				cout<<"Next: NULL"<<endl;
			} else {
				cout<<"Next: " << p->next->data<<endl;
			}
	 		cout<<"----------------------------"<<endl;
			cout<<"|"<<endl;
			cout<<"v"<<endl;
			
		}
	}
}


void insertAt(int position, int element){
	if(position > count){
		cout << "Invalid position!\n";
		return;
	}
	Node *tempNode = new Node();
	tempNode->data = element;
	tempNode->next = NULL;
	tempNode->prev = NULL;

	if(position == 1){
		insertBegin(element);
		return;
	}

	Node *currentNode = head;
	for(int i=1; i<position-1; i++){
		currentNode = currentNode->next;
	}

	tempNode->prev = currentNode;
	tempNode->next = currentNode->next;
	currentNode->next->prev = tempNode;
	currentNode->next = tempNode;
	count++;
}

int max(){
	if(listSize()==0){
		cout <<"List Empty\n";
		return -1;
	} else {
		int maxVal = head->data;
		for(Node *p = head; p!=NULL; p=p->next){
			if(p->data > maxVal){
				maxVal = p->data;
			}
		}
		return maxVal;
	}
}

int min(){
	if(listSize()==0){
		cout <<"List Empty\n";
		return -1;
	} else {
		int minVal = head->data;
		for(Node *p = head; p!=NULL; p=p->next){
			if(p->data < minVal){
				minVal = p->data;
			}
		}
		return minVal;
	}
}

int at(int position){
	if(position > count){
		cout << "Invalid position!\n";
		return -1;
	}
	Node *currentNode = head;
	for(int i=1; i<position; i++){
		currentNode = currentNode->next;
	}
	return currentNode->data;
}


void deleteFront(){
	if(head == NULL){
		cout << "List Empty!\n";
		return;
	}
	Node *tempNode = head;
	head = head->next;
	if(head != NULL){
		head->prev = NULL;
	}
	delete tempNode;
	count--;
}


void deleteBack(){
	if(head == NULL){
		cout << "List Empty!\n";
		return;
	}
	Node *lastNode = head;
	while(lastNode->next != NULL){
		lastNode = lastNode->next;
	}
	if(lastNode == head){
		head = NULL;
	} else {
		lastNode->prev->next = NULL;
	}
	delete lastNode;
	count--;
}


void printHeadToEnd(){
	if(listSize()==0){
		cout <<"List Empty\n";
	} else {
		cout <<"List Elements are: \n";
		for(Node *p = head; p!=NULL; p=p->next){
			cout<<"------------------------------"<<endl;

			cout<<"Data: " << p->data<<endl;

	 		cout<<"----------------------------"<<endl;
			cout<<"|"<<endl;
			cout<<"v"<<endl;
		}
	}
}


void printEndToHead(){
	if(listSize()==0){
		cout <<"List Empty\n";
	} else {
		cout <<"List Elements are: \n";
		Node *lastNode = head;
		while(lastNode->next != NULL){
			lastNode = lastNode->next;
		}
		for(Node *p = lastNode; p!=NULL; p=p->prev){
			
			cout<<"Data: " << p->data<<endl;

	 		cout<<"----------------------------"<<endl;
			cout<<"|"<<endl;
			cout<<"v"<<endl;
		}
	}
}


