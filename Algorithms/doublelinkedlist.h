#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "doublenode.h"
#include <iostream>

//Note: class is using zero (0) based index. First element is at index 0.

class DoubleLinkedList {

private:
	
	DoubleNode* head; //to mark the start/head of the list or beginning
	DoubleNode* tail; //to mark the end/tail of the list or ending
	int size; //to track size of the list

public:

    //Default constructor of the class
    DoubleLinkedList() {
        size = -1;
        head = nullptr;
        tail = nullptr;
    }

    // Function to return the size of the linked list.
    int getSize() const {
        return this->size + 1;
    }

    //Function to check if the list is empty
    bool isEmpty() const {
        return (size == -1);
    }

    //Function to return the head or start of the list
    DoubleNode* getHead() const {
        return head;
    }

    //Function to return the tail or end of the list
    DoubleNode* getTail() const {
        return tail;
    }

    //Function to insert data at the start of the list which is head of the list
    void insertAtHead(int data) {
        DoubleNode* newNode = new DoubleNode(data);
        if (isEmpty()) { //if list is empty then head and tail would both point to same node (single node in the list)
            head = newNode;
            tail = newNode;           
        }
        else {
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void insertAtTail(int data) {
        DoubleNode* newNode = new DoubleNode(data);
        if (isEmpty()) {
            tail = newNode;
            head = newNode;
        }
        else {
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void insertAt(int index, int data) {
        if (index < 0 || index > size+1) {
            std::cout << "\nIndex out of range\n";
            return;
        }

        
        if (index == 0) {
            insertAtHead(data);
            return;
        }
        DoubleNode* current = getNodeAt(index);
        DoubleNode* newNode = new DoubleNode(data);

        newNode->previous = current->previous;
        newNode->next = current;
        current->previous->next = newNode;
        current->previous = newNode;
        size++;
    }

    void deleteAtHead() {
        if (isEmpty()) {
            std::cout << "\n Head is already null. Nothing to delete \n";
        }

        if (size == 0) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            DoubleNode* headToDelete = head;
            head = head->next;
            head->previous = nullptr;
            delete headToDelete;
        }

        size--;

    }
    void deleteAtTail() {
        if (isEmpty()) {
            std::cout << "\n Tail is already null. Nothing to delete \n";
        }

        if (size == 0) {
            delete tail;
            tail = nullptr;
            head = nullptr;
        }
        else {
            DoubleNode* tailToDelete = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete tailToDelete;
        }
        size--;
    }
    void deleteAt(int index) {
        if (index < 0 || index > size) {
            std::cout << "\nIndex out of range\n";
            return;
        }

        if (index == 0) {
            deleteAtHead();
            return;

        } else if (index == size) {
            deleteAtTail();
            return;
        }
        else {
            DoubleNode* nodeToDelete = getNodeAt(index);

            nodeToDelete->previous->next = nodeToDelete->next;
            nodeToDelete->next->previous = nodeToDelete->previous;
            delete nodeToDelete;
            size--;
        }
        
    }

    //Function to clear the list (empty).
    void clear() {
        while (!isEmpty()) {
            deleteAtHead();
        }
    }

    /**********Helper functions**********/

    //Function to retrieve a node at given index. Note: Index is implemented using private variable size / getSize() function.
    DoubleNode* getNodeAt(int index) const {
        if (index < 0 || index > size+1) {
            std::cout << "\nIndex out of range \n";
            return nullptr;
        }

        DoubleNode* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    void swapNodes(DoubleNode* node1, DoubleNode* node2) {
        if (node1 == nullptr || node2 == nullptr || node1 == node2) {
            return;
        }

        if (node1->next == node2) {
            node1->next = node2->next;
            node2->next = node1;
            node2->previous = node1->previous;
            node1->previous = node2;

            if (node1->next != nullptr) {
                node1->next->previous = node1;
            }
            else {
                tail = node1;
            }
            if (node2->previous != nullptr) {
                node2->previous->next = node2;
            }
            else {
                head = node2;
            }

            return;
        }

        if (node2->next == node1) {
            node2->next = node1->next;
            node1->next = node2;
            node1->previous = node2->previous;
            node2->previous = node1;

            if (node2->next != nullptr) {
                node2->next->previous = node2;
            }
            else {
                tail = node2;
            }
            if (node1->previous != nullptr) {
                node1->previous->next = node1;
            }
            else {
                head = node1;
            }

            return;
        }

        DoubleNode* temp_prev = node1->previous;
        DoubleNode* temp_next = node1->next;

        node1->previous = node2->previous;
        node1->next = node2->next;
        node2->previous = temp_prev;
        node2->next = temp_next;

        if (node1->previous != nullptr) {
            node1->previous->next = node1;
        }
        else {
            head = node1;
        }
        if (node1->next != nullptr) {
            node1->next->previous = node1;
        }
        else {
            tail = node1;
        }
        if (node2->previous != nullptr) {
            node2->previous->next = node2;
        }
        else {
            head = node2;
        }
        if (node2->next != nullptr) {
            node2->next->previous = node2;
        }
        else {
            tail = node2;
        }
    }




    void sort() {

        if (size == -1 || size == 0) { //if list is empty or has only one node, no need to sort
            return;
        }

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j <= size; j++) {
                if (getNodeAt(i)->data > getNodeAt(j)->data) {
                    swapNodes(getNodeAt(i), getNodeAt(j));
                }
            }
        }

        /* In this implementation only data is swapped*/
        //if (size == -1 || size == 0) { //if list is empty or has only one node, no need to sort
        //    return;
        //}
        //for (DoubleNode* i = head; i->next != nullptr; i = i->next) {
        //    for (DoubleNode* j = i->next; j != nullptr; j = j->next) {
        //        if (i->data > j->data) {
        //            int temp = i->data;
        //            i->data = j->data;
        //            j->data = temp;
        //        }
        //    }
        //}

    }



    void print() {
        std::cout << "\n\n LIST: ";
        DoubleNode* current = head;
        while (current != nullptr) {
            std::cout << current->data << "-->";
            current = current->next;
        }

        std::cout << "\n\n";
    }
    //Destructor of the class
    ~DoubleLinkedList() {
        clear();
    }

    

};

#endif