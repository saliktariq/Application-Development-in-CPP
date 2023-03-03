#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

struct Node {
    int position;
    bool isSafe;
    vector<int> playersAtThisPosition;
    Node* prev;
    Node* next;
};

Node *head = NULL;
int mycount = 0;


void insertEnd(int position, bool isSafe, vector<int> playersAtThisPosition) {
    Node *tempNode = new Node;
    tempNode->position = position;
    tempNode->isSafe = isSafe;
    tempNode->playersAtThisPosition = playersAtThisPosition;
    tempNode->next = NULL;
    tempNode->prev = NULL;

    if (head == NULL) {
        head = tempNode;
    } else {
        Node *lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = tempNode;
        tempNode->prev = lastNode;
    }
    mycount++;
}

void updateNodeAtPosition(int position, bool isSafe, vector<int> playersAtThisPosition) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->position == position) {
            current->position = position;
            current->isSafe = isSafe;
            current->playersAtThisPosition = playersAtThisPosition;
    //        cout << "The node at position " << position << " has been updated." << endl;
            return;
        }
        current = current->next;
    }

    cout << "The node at position " << position << " could not be found." << endl;
}

Node* getNodeAtPosition(int position) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return NULL;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->position == position) {
            return current;
        }
        current = current->next;
    }

    cout << "The node at position " << position << " could not be found." << endl;
    return NULL;
}

void printPlayersAtThisPositionVector(vector<int> v) {
	cout <<"\nPlayers at this position:\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void setup(){
		//Populating linkedList with number values
	vector<int> playersAtThisPosition;
	for (int i = 1; i < 48; i++){
		insertEnd(i,false, playersAtThisPosition);
	}
	
	//Populating linkedList with safe values
	updateNodeAtPosition(3, true,  playersAtThisPosition);	
	updateNodeAtPosition(9, true,  playersAtThisPosition);	
	updateNodeAtPosition(15, true, playersAtThisPosition);	
	updateNodeAtPosition(21, true, playersAtThisPosition);	
	updateNodeAtPosition(23, true, playersAtThisPosition);	
	updateNodeAtPosition(27, true, playersAtThisPosition);	
	updateNodeAtPosition(31, true, playersAtThisPosition);	
	updateNodeAtPosition(35, true, playersAtThisPosition);	
	
	
}

void display() {
    Node *current = head;
    while (current != NULL) {
        cout << "Position: " << current->position << endl;
        cout << "Is Safe: " << current->isSafe << endl;
        cout << "Players at this position: ";
        for (int i = 0; i < current->playersAtThisPosition.size(); i++) {
            cout << current->playersAtThisPosition[i] << " ";
        }
        cout << endl << endl;
        current = current->next;
    }
}

void colourMyConsole(){
		HANDLE myConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(myConsole, 100);
	system("cls");
}

void displayBoard() {
    // not implemented yet
}



    
