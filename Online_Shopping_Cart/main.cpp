#include <iostream>
using namespace std;


#include "ShoppingCart.h"



/*
(4) Implement the PrintMenu() function in main.cpp 
to print the following menu of options to manipulate 
the shopping cart. (1 pt)
*/

void PrintMenu() {
	std::cout << "MENU" << endl;
	std::cout << "a - Add item to cart" << endl;
	std::cout << "d - Remove item from cart" << endl;
	std::cout << "c - Change item quantity" << endl;
	std::cout << "i - Output items' descriptions" << endl;
	std::cout << "o - Output shopping cart" << endl;
	std::cout << "q - Quit";
}

/*
(5) Implement the ExecuteMenu() function in main.cpp that takes 2 parameters: 
a character representing the user's choice and the reference of a shopping cart. 
ExecuteMenu() performs the menu options described below, 
according to the user's choice. (1 pt)
*/

void ExecuteMenu(char option, ShoppingCart& theCart) {

	switch (option) {
	case 'q': 
	{
		break;
	}
	case 'o':
	{
		std::cout << "OUTPUT SHOPPING CART" << endl;
		theCart.PrintTotal();
		cout << endl;
		break;
	}

	case 'i':
	{
		std::cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
		theCart.PrintDescriptions();
		break;
	}

	case 'a':
	{
		string itemName;
		string description;
		int itemPrice;
		int itemQuantity;

		std::cout << "ADD ITEM TO CART" << endl;
		std::cout << "Enter the item name:" << endl;
		cin.ignore();
		getline(cin, itemName); 
		
		std::cout << "Enter the item description:" << endl;	
		cin.ignore();
		getline(cin, description);
		
		std::cout << "Enter the item price:" << endl;
		cin >> itemPrice;
		std::cout << "Enter the item quantity:" << endl;
		cin >> itemQuantity;
		
		ItemToPurchase item(itemName, description, itemPrice, itemQuantity);
		theCart.AddItem(item);
		break;
	}

	case 'd':
	{
		std::cout << "REMOVE ITEM FROM CART" << endl;
		std::cout << "Enter name of item to remove:" << endl;
		
		string itemToRemove;
	    cin.ignore();
		getline(cin, itemToRemove);
		theCart.RemoveItem(itemToRemove);
		break;
	}

	case 'c':
	{
		std::cout << "CHANGE ITEM QUANTITY" << endl;
		std::cout << "Enter the item name:" << endl;
		string itemName;
		cin.ignore();
		getline(cin, itemName);

		for (int i = 0; i < theCart.GetNumItemsInCart(); i++) {
			if (theCart.GetCartItems()[i].GetName() == itemName) {
				ItemToPurchase tempItem = theCart.GetCartItems()[i];
				ItemToPurchase temp2 = tempItem;
				theCart.RemoveItem(itemName);
				int newQuantity = 0;
				std::cout << "Enter the new quantity:" << endl;
				
				cin >> newQuantity;
				temp2.SetQuantity(newQuantity);
				theCart.AddItem(temp2);

			}
			else {
				cout << "Item not found in cart. Nothing modified." << endl;

			}

		}
		break;
	}

	//{
	//	std::cout << "CHANGE ITEM QUANTITY" << endl;
	//	std::cout << "Enter the item name:" << endl;
	//	string itemName;
	//	cin.ignore();
	//	getline(cin, itemName);

	//	for (int i = 0; i < theCart.GetNumItemsInCart(); i++) {
	//		if (theCart.GetCartItems()[i].GetName() == itemName) {
	//			ItemToPurchase tempItem = theCart.GetCartItems()[i];
	//			theCart.RemoveItem(itemName);
	//			int newQuantity = 0;
	//			std::cout << "Enter the new quantity:" << endl;

	//			cin >> newQuantity;
	//			tempItem.SetQuantity(newQuantity);
	//			theCart.AddItem(tempItem);

	//		}
	//		else {
	//			cout << "Item not found in cart. Nothing modified." << endl;
	//			cout << endl;
	//		}

	//	}
	//	break;
	//}

	default:
			break;

	}



}


int main() {

	/*
	(3) In main(), prompt the user for a customer's name and today's date.
	Output the name and date. Create an object of type ShoppingCart. (1 pt)
	*/
	
	string customerName, todaysDate;

	std::cout << "Enter customer's name:" << endl;

	getline(cin, customerName);

	std::cout << "Enter today's date:" << endl;

	getline(cin, todaysDate);

	std::cout << endl;

	std::cout << "Customer name: " << customerName << endl;
	std::cout << "Today's date: " << todaysDate << endl;


	ShoppingCart shoppingCart(customerName, todaysDate);


	/*
	(6) In main(), call PrintMenu() and prompt for the user's choice of menu options.
	Each option is represented by a single character.
	*/

	
	

	char option;
	do {
		cout << endl;
		PrintMenu();
		cout << endl; cout << endl;
		cout << "Choose an option:" << endl;
		
		cin >> option;
		while (option != 'a' && option != 'd' && option != 'c' && option != 'i' && option != 'o' && option != 'q') {
			cout << "Choose an option:" << endl;
			cin >> option;
		} 
		ExecuteMenu(option, shoppingCart);

	} while (option != 'q');
	return 0;
}