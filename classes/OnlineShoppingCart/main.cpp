#include <iostream>
#include "ItemToPurchase.cpp"
#include "ShoppingCart.cpp"
#include <string>



using namespace std;

//(4) Implement the PrintMenu() function in main.cpp to print the following menu of options to manipulate the shopping cart.
void PrintMenu() {
cout << "MENU" << endl;
cout << "a - Add item to cart" << endl;
cout << "d - Remove item from cart" << endl;
cout << "c - Change item quantity" << endl;
cout << "i - Output items' descriptions" << endl;
cout << "o - Output shopping cart" << endl;
cout << "q - Quit" << endl;
}

/*
(5) Implement the ExecuteMenu() function in main.cpp that takes 2 parameters: 
a character representing the user's choice and the reference of a shopping cart. 
ExecuteMenu() performs the menu options described below, according to the user's choice.
*/
void ExecuteMenu(char choice, ShoppingCart& cart) {
string name, description, date;
string price, quantity;
ItemToPurchase item;
switch (choice) {
	
	case 'q':
		break;
case 'a':
cout << "ADD ITEM TO CART" << endl;
cout << "Enter the item name:" << endl;
cin.ignore();
getline(cin, name);

item.SetName(name);
cout << "Enter the item description:" << endl;
cin.ignore();
getline(cin, description);

item.SetDescription(description);
cout << "Enter the item price:" << endl;

cin >> price;
if(isdigit(stoi(price))){
	item.SetPrice(stoi(price));
}

cout << "Enter the item quantity:" << endl;
cin >> quantity;
if(isdigit(stoi(quantity))){
item.SetQuantity(stoi(quantity));
cart.AddItem(item);	
}

break;
case 'd':
cout << "REMOVE ITEM FROM CART" << endl;
cout << "Enter name of item to remove:" << endl;
cin.ignore();
getline(cin, name);

cart.RemoveItem(name);
break;
case 'c':
cout << "CHANGE ITEM QUANTITY" << endl;
cout << "Enter the item name:" << endl;
cin.ignore();
getline(cin, name);

cout << "Enter the new quantity:" << endl;
cin >> quantity;
item.SetName(name);
item.SetQuantity(stoi(quantity));
cart.ModifyItem(item);
break;
case 'i':
	cout<<"OUTPUT ITEMS' DESCRIPTIONS\n";
cart.PrintDescriptions();

break;
case 'o':
cout<<"OUTPUT SHOPPING CART\n";	
cart.PrintTotal();

break;

default:
break;
}
}

int main() {
	
	string customerName, date;
cout << "Enter customer's name:" << endl;

getline(cin, customerName);


cout << "Enter today's date:" << endl;
getline(cin, date);

ShoppingCart cart(customerName, date);
char choice = ' ';
cout<<"\nCustomer name: " << customerName<<endl;
cout<<"Today's date: " << date << endl;
cout<< endl;

PrintMenu();
cout<< endl;
do {
    
    
    cout << "Choose an option:" << endl;
    cin >> choice;
    ExecuteMenu(choice, cart);
} while (choice != 'q');

return 0;

   

}
