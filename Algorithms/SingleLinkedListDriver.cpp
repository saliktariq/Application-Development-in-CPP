#include "singlelinkedlist.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList myList;

    int choice, value, data;
    SingleNode* node;

    do {
        cout << "\n\nLinked List Operations\n";
        cout << "1. Insert a node at the beginning\n";
        cout << "2. Insert a node at the end\n";
        cout << "3. Insert a node after a given node\n";
        cout << "4. Insert a node before a given node\n";
        cout << "5. Delete a node with given data\n";
        cout << "6. Print the linked list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";

        

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            myList.insertAtBeginning(value);
            cout << "Node inserted at the beginning." << endl;
            myList.print();
            break;

        case 2:
            cout << "Enter the value to insert: ";
            cin >> value;
            myList.insertAtEnd(value);
            cout << "Node inserted at the end." << endl;
            myList.print();
            break;

        case 3:
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the data of the node after which to insert: ";
            cin >> data;
            node = myList.search(data);
            if (node != nullptr) {
                myList.insertAfter(node, value);
                cout << "Node inserted after the given node." << endl;
            }
            else {
                cout << "Node with given data not found." << endl;
            }
            myList.print();
            break;

        case 4:
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the data of the node before which to insert: ";
            cin >> data;
            node = myList.search(data);
            if (node != nullptr) {
                myList.insertBefore(node, value);
                cout << "Node inserted before the given node." << endl;
            }
            else {
                cout << "Node with given data not found." << endl;
            }
            myList.print();
            break;

        case 5:
            cout << "Enter the data of the node to delete: ";
            cin >> data;
            myList.deleteNode(data);
            cout << "Node deleted." << endl;
            myList.print();
            break;

        case 6:
            myList.print();
            break;

        case 7:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 7);

    return 0;
}
