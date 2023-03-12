#include <iostream>
#include "DoubleLinkedList.h"



int main() {
    DoubleLinkedList list;
       

    int choice = 0;
    do {
        std::cout << "\n\n----------------------------------------\n";
        std::cout << "\n\nCurrent list: ";
        DoubleNode* current = list.getHead();
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
        std::cout << "Choose an option:\n";
        std::cout << "1. Insert at head\n";
        std::cout << "2. Insert at tail\n";
        std::cout << "3. Insert at index\n";
        std::cout << "4. Delete at head\n";
        std::cout << "5. Delete at tail\n";
        std::cout << "6. Delete at index\n";
        std::cout << "7. Sort list\n";
        std::cout << "8. Clear list\n";
        std::cout << "9. Quit\n";
        std::cin >> choice;

        int data, index;
        switch (choice) {
        case 1:
            std::cout << "Enter data to insert at head: ";
            std::cin >> data;
            list.insertAtHead(data);
            break;
        case 2:
            std::cout << "Enter data to insert at tail: ";
            std::cin >> data;
            list.insertAtTail(data);
            break;
        case 3:
            std::cout << "Enter index to insert at: ";
            std::cin >> index;
            std::cout << "Enter data to insert: ";
            std::cin >> data;
            list.insertAt(index, data);
            break;
        case 4:
            list.deleteAtHead();
            break;
        case 5:
            list.deleteAtTail();
            break;
        case 6:
            std::cout << "Enter index to delete: ";
            std::cin >> index;
            list.deleteAt(index);
            break;
        case 7:
            list.sort();
            break;
        case 8:
            list.clear();
            break;
        case 9:
            std::cout << "Quitting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 9);

    return 0;
}
