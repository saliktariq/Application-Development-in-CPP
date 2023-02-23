#include <iostream>
#define MAX_SIZE 1000
using namespace std;



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

int pop_bottom() {
    if (top == -1) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    int data = arr[0];
    for (int i = 0; i < top; i++) {
        arr[i] = arr[i + 1];
    }
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
        cout << "4. Pop element from bottom\n";
        cout << "5. Display stack elements\n";
        cout << "6. Exit\n";
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
                    cout << "Popped element from top is: " << data << endl;
                }
                break;
            case 4:
                data = pop_bottom();
                if (data != -1) {
                    cout << "Popped element from bottom is: " << data << endl;
                }
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    return 0;
}

