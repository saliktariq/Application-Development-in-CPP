#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "singlenode.h"
#include<iostream>


/* Very important note to self: In most operations in linkedlist, we need three references (three nodes); head (representing start of the list),
current (representing current node which will alter the node)
and lastly next (which is the next or last node in the operation.*/

class LinkedList {
public:
	SingleNode* head;

	LinkedList() {
		head = nullptr;
	}

	// Helper function to create a node with given data

	SingleNode* makeNode(int data) {
		SingleNode* newNode = new SingleNode(data);
		return newNode;
	}

	// Function to insert a node at the beginning (head) of the linked list

	void insertAtBeginning(int value) {
		SingleNode* newNode = makeNode(value);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	// Function to insert a node at the end of the linked list

	void insertAtEnd(int value) {
		SingleNode* newNode = makeNode(value);
		if (head == nullptr) {
			head = newNode;
			return;
		}

		// Need this so that current can be iterated forward to reach the desired position i.e., end of the list
		SingleNode* current = head;
		while (current->next != nullptr) {
			current = current->next; //iterate to the end
		}

		//at this point current is at the next because current->next is nullptr
		current->next = newNode; // connected the new node at the next pointer of current node (which is last node)
	}

	// Function to insert a node AFTER a given node in a linked list

	void insertAfter(SingleNode* givenNode, int value) {
		if (givenNode == nullptr) {
			return;
		}
		SingleNode* newNode = makeNode(value);
		newNode->next = givenNode->next;
		givenNode->next = newNode;
	}

	// Function to insert a node BEFORE a given node in a linked list

	void insertBefore(SingleNode* givenNode, int value) {
		if (givenNode == nullptr) {
			return;
		}
		SingleNode* newNode = makeNode(value);

		//Check if givenNode is the head (first) node
		if (givenNode == head) {
			newNode->next = head;
			head = newNode;
			return;
		}

		//Otherwise, create two pointers to mark two positions: current and previous
		SingleNode* current = head;
		SingleNode* previous = nullptr; // because we start from head
		while (current != nullptr && current != givenNode) {
			previous = current;
			current = current->next;
		}
		if (current == nullptr) { //we did not find the given node
			return; 
		}
		newNode->next = givenNode;
		previous->next = newNode;
	}

	// Function to delete a node given its data

	void deleteNode(int data) {
		if (head == nullptr) {
			return;
		}
		

		SingleNode* current = head;
		SingleNode* previous = nullptr;

		while (current != nullptr && current->data != data) {
			previous = current;
			current = current->next;
		}
		if (current == nullptr) {
			return;
		}
		if (previous == nullptr) { //this would happen if head contains the data to delete
			head = head->next;
		}
		else {
			previous->next = current->next;
		}
		current->data = NULL;
		current->next = nullptr;
		delete current; // get rid of deleted node properly 

	}

	// Function to search for data and return that node

	SingleNode* search(int value) {
		if (head == nullptr) {
			return nullptr;
		}

		SingleNode* current = head;
		while (current != nullptr && current->data != value) {
			current = current->next;
		}
		if (current == nullptr) {
			return nullptr;
		}
		else {
			return current;
		}
	}

	// Function to print the linked list

	void print() {
		if (head == nullptr) {
			std::cout << "\n The list is empty. \n";
			return;
		}
		// Need this so that current can be iterated forward to reach the end of the list
		SingleNode* current = head;
		std::cout << "Linked List : ";
		while (current != nullptr) {
			std::cout << current->data << "-->";
			current = current->next;
		}
		std::cout << std::endl;
	}

	// Destructor to delete all nodes of the linked list 

	~LinkedList() {
		SingleNode* current = head;
		while (current != nullptr) {
			SingleNode* temporaryVariable = current;
			current = current->next;
			delete temporaryVariable;
		}

		head = nullptr;
	}

};
#endif