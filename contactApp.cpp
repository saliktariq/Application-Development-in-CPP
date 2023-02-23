#include <iostream>
#include <string>

using namespace std;

struct Contact {
    int id;
    string name;
    string email;
};

Contact contacts[100];
int contactCount = 0;

void insertContact() {
    if (contactCount == 100) {
        cout << "Contact list is full!" << endl;
        return;
    }
    Contact contact;
    cout << "Enter contact id: ";
    cin >> contact.id;
    cout << "Enter contact name: ";
    cin.ignore();
    getline(cin, contact.name);
    cout << "Enter contact email: ";
    getline(cin, contact.email);
    contacts[contactCount] = contact;
    contactCount++;
    cout << "Contact added successfully!" << endl;
}

void updateContact() {
    int id;
    cout << "Enter contact id to update: ";
    cin >> id;
    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].id == id) {
            cout << "Enter new contact name: ";
            cin.ignore();
            getline(cin, contacts[i].name);
            cout << "Enter new contact email: ";
            getline(cin, contacts[i].email);
            cout << "Contact updated successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

void deleteContact() {
    int id;
    cout << "Enter contact id to delete: ";
    cin >> id;
    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].id == id) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j+1];
            }
            contactCount--;
            cout << "Contact deleted successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

void searchContact() {
    int id;
    cout << "Enter contact id to search: ";
    cin >> id;
    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].id == id) {
            cout << "Contact found!" << endl;
            cout << "ID: " << contacts[i].id << endl;
            cout << "Name: " << contacts[i].name << endl;
            cout << "Email: " << contacts[i].email << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

void displayAllContacts() {
    if (contactCount == 0) {
        cout << "No contacts found!" << endl;
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        cout << "ID: " << contacts[i].id << endl;
        cout << "Name: " << contacts[i].name << endl;
        cout << "Email: " << contacts[i].email << endl;
        cout << endl;
    }
}


int main(){
	
	int option = -1;
	do{
		cout<<"**********MENU**********"<<endl;
		cout<<"Enter 1 to INSERT"<<endl;
		cout<<"Enter 2 to UPDATE"<<endl;
		cout<<"Enter 3 to DELETE"<<endl;
		cout<<"Enter 4 to SEARCH BY ID"<<endl;
		cout<<"Enter 5 to DISPLAY ALL CONTACTS"<<endl;
		cout<<"Enter 6 to DISPLAY A CONTACT BY NAME"<<endl;
		cout<<"Enter 0 to EXIT"<<endl;
		
		cin>>option;
		
		switch(option){
			case 1:
				insertContact();	
				break;
			case 2:
				updateContact();
				break;
			case 3:
				deleteContact();	
				break;
			case 4:
				searchContact();
				break;
			case 5:
				displayAllContacts();	
				break;
			case 6:
				cout << "Not implemented yet!" << endl;
				break;
			
			default:
				break;
		}

			
		
	}while(option!=0);
	
	return 0;
}

