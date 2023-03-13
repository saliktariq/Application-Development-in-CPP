#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
	customerName = "none";
	currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string customerName= "none", string currentDate = "January 1, 2016") {
	this->customerName = customerName;
	this->currentDate = currentDate;
}

string ShoppingCart::GetCustomerName() const {
	return this->customerName;
}

string ShoppingCart::GetDate() const {
	return this->currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
	if (&item != nullptr) { // check if item is not null
		cartItems.push_back(item);
	}
}

void ShoppingCart::RemoveItem(string itemName) {
	bool found = false;
	for (int i = 0; i < cartItems.size(); i++) {
		if (cartItems[i].GetName() == itemName) {
			cartItems.erase(cartItems.begin() + i);
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "Item not found in cart. Nothing removed.\n";
	}

}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
	bool found = false;
	for (int i = 0; i < cartItems.size(); i++) {
		if (cartItems[i].GetName() == item.GetName()) {
			if (cartItems[i].GetDescription() != "none") {
				cartItems[i].SetDescription("none");
			}
			if (cartItems[i].GetPrice() != 0) {
				cartItems[i].SetPrice(0);
			}
			if (cartItems[i].GetQuantity() != 0) {
				cartItems[i].SetQuantity(0);
			}

			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "Item not found in cart. Nothing modified.\n";
	}
}

int ShoppingCart::GetNumItemsInCart() const {
	return cartItems.size();
}

int ShoppingCart::GetCostOfCart() const {
	int sumOfCart = 0;
	for (int i = 0; i < cartItems.size(); i++) {

		sumOfCart += cartItems[i].GetPrice();
		
	}

	return sumOfCart;
}

void ShoppingCart::PrintTotal() const {


	std::cout << this->GetCustomerName() << "'s Shopping Cart - " << this->GetDate() << endl;
	std::cout << "Number of Items :" << this->GetNumItemsInCart() << endl;
	std::cout << endl;

	for (int i = 0; i < cartItems.size(); i++) {
		cartItems[i].PrintItemCost();
	}

	if (cartItems.size() == 0) {
		std::cout << "SHOPPING CART IS EMPTY" << endl;
	}

	std::cout << endl;
	std::cout << "Total: $" << this->GetCostOfCart() << endl; //double check this endl 
}

void ShoppingCart::PrintDescriptions() const {
	std::cout << this->GetCustomerName() << "'s Shopping Cart - " << this->GetDate() << endl;
	std::cout << endl;
	std::cout << "Item Descriptions" << endl;
	for (int i = 0; i < cartItems.size(); i++) {
		cartItems[i].PrintItemDescription();
	}
}
