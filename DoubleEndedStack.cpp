#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack overflow" << endl;
        return;
    }
    top++;
    arr[top] = data;
}

void push_bottom(int data) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack overflow" << endl;
        return;
    }
    for (int i = top; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    top++;
    arr[0] = data;
}

int pop() {
    if (top == -1) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    int data = arr[top];
    top--;
    return data;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements are:" << endl;
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << endl;
    }
}

int main() {
    int choice, data;

    do {
        cout << "\n1. Push element on top\n";
        cout << "2. Push element on bottom\n";
        cout << "3. Pop element from top\n";
        cout << "4. Display stack elements\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> data;
                push(data);
                break;
            case 2:
                cout << "Enter element to push on bottom: ";
                cin >> data;
                push_bottom(data);
                break;
            case 3:
                data = pop();
                if (data != -1) {
                    cout << "Popped element is: " << data << endl;
                }
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}

