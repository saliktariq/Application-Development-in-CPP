#include <iostream>

using namespace std;

struct ChildNode {
    int data;
    struct ChildNode* next;
};

struct Node {
    int data;
    struct Node* down;
    struct ChildNode* next;
};

Node* head = NULL;
ChildNode* childHead = NULL;

void createLinkedListStructure(int element) {
    Node* tempNode = new Node();
    tempNode->data = element;
    tempNode->next = NULL;
    tempNode->down = NULL;

    if (head == NULL) {
        head = tempNode;
    } else {
        Node* lastNode = head;
        while (lastNode->down != NULL) {
            lastNode = lastNode->down;
        }
        lastNode->down = tempNode;
    }
}

void reset() {
    for (int i = 0; i < 4; i++) {
        createLinkedListStructure(i);
    }
}

void insertEnd(int element) {
    int roundRobin = element % 4;

    ChildNode* tempNode = new ChildNode();
    tempNode->data = element;
    tempNode->next = NULL;

    Node* parentNode = head;
    while (parentNode != NULL) {
        if (parentNode->data == roundRobin) {
            if (parentNode->next == NULL) {
                parentNode->next = tempNode;
                childHead = tempNode;
            } else {
                ChildNode* lastNode = parentNode->next;
                while (lastNode->next != NULL) {
                    lastNode = lastNode->next;
                }
                lastNode->next = tempNode;
            }
            break;
        }
        parentNode = parentNode->down;
    }
}

void displayParentList() {
    if (head == NULL) {
        cout << "List Empty\n";
    } else {
        cout << "List Elements are: \n";
        for (Node* p = head; p != NULL; p = p->down) {
            cout << p->data << "-->";
            for (ChildNode* q = p->next; q != NULL; q = q->next) {
                cout << q->data << "-->";
            }
            cout << "\n";
        }
    }
}


