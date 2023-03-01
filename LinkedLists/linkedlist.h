#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node *head = NULL;
int count = 0;

void insertBegin(int element){
	Node *tempNode = new Node();
	
	tempNode->data = element;
	tempNode->next = head;
	head = tempNode;
	count++;
}

void insertEnd(int element){
	Node *tempNode = new Node();
	tempNode->data = element;
	tempNode->next = NULL;
	
	if(head == NULL){
		head = tempNode;
	} else {
		Node *lastNode = head;
		while(lastNode->next != NULL){
			lastNode = lastNode->next;
		}
		lastNode->next = tempNode;
	}
	count++;
}

void insertAtPosition(int element, int position){
    if(position < 1 || position > count + 1){
        cout << "Invalid position\n";
        return;
    }

    Node *tempNode = new Node();
    tempNode->data = element;

    if(position == 1){
        tempNode->next = head;
        head = tempNode;
    } else {
        Node *prevNode = head;
        for(int i=1; i<position-1; i++){
            prevNode = prevNode->next;
        }
        tempNode->next = prevNode->next;
        prevNode->next = tempNode;
    }
    count++;
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* tempNode = head;
    head = head->next;
    cout<<"Deleting: "<< tempNode->data;
    delete tempNode;
    count--;
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* tempNode = head;
    Node* prevNode = NULL;
    while (tempNode->next != NULL) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    if (prevNode == NULL) {
        head = NULL;
    } else {
        prevNode->next = NULL;
    }
    cout<<"Deleting: "<< tempNode->data;
    delete tempNode;
    count--;
}


void deleteFromPosition(int position) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (position < 1 || position > count) {
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 1) {
    	deleteFromBeginning();
    	return;
    }
    if (position == count){
    	deleteFromEnd();
    	return;   	
	}
    
    Node* tempNode = head;
    for (int i = 1; i < position - 1; i++) {
        tempNode = tempNode->next;
    }
    Node* deleteNode = tempNode->next;
    tempNode->next = deleteNode->next;
    cout<<"Deleting: "<< deleteNode->data;
    delete deleteNode;
    count--;
}


void displayList(){
	if(head == NULL){
		cout <<"List Empty\n";
	} else {
		cout <<"List Elements are: \n\t\t\t";
		for(Node *p = head; p!=NULL; p=p->next){
			cout<<p->data<<"-->";
		}
	}
}

Node* at(int position){
	if(position < 1 || position > count){
		return NULL;
	}
	Node *tempNode = head;
	for(int i=1; i<position; i++){
		tempNode = tempNode->next;
	}
	return tempNode;
}

Node* max(){
	
	if(head == NULL){
		return NULL;
	}
	
	Node* maximumNode = head;
	Node* nextNode = head->next;
	while(nextNode!=NULL){
		if(nextNode->data > maximumNode->data){
			maximumNode = nextNode;
		}
		
		nextNode = nextNode->next;
	}
	
	return maximumNode;
	
}

Node* min(){
		if(head == NULL){
		return NULL;
	}
	
	Node* minimumNode = head;
	Node* nextNode = head->next;
	while(nextNode!=NULL){
		if(nextNode->data < minimumNode->data){
			minimumNode = nextNode;
		}
		
		nextNode = nextNode->next;
	}
	
	return minimumNode;
}

void swapAlternative() {
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode = head->next;

    while (nextNode != NULL) {
        currNode->next = nextNode->next;
        nextNode->next = currNode;
        if (prevNode != NULL) {
            prevNode->next = nextNode;
        } else {
            head = nextNode;
        }
        prevNode = currNode;
        currNode = currNode->next;
        if (currNode != NULL) {
            nextNode = currNode->next;
        } else {
            nextNode = NULL;
        }
    }
}

