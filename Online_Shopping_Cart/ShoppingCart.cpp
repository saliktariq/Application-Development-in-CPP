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
	cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName) {
	bool found = false;
	for (size_t i = 0; i < cartItems.size(); i++) {
		if (cartItems[i].GetName() == itemName) {
			cartItems.erase(cartItems.begin() + i);
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "Item not found in cart. Nothing removed.\n";
		//std::cout << endl;
	}

}

//void ShoppingCart::ModifyItem(ItemToPurchase item) {
//	bool found = false;
//	for (size_t i = 0; i < cartItems.size(); i++) {
//		if (cartItems[i].GetName() == item.GetName()) {
//			if (cartItems[i].GetDescription() != "none") {
//				cartItems[i].SetDescription("none");
//			}
//			if (cartItems[i].GetPrice() != 0) {
//				cartItems[i].SetPrice(0);
//			}
//			if (cartItems[i].GetQuantity() != 0) {
//				cartItems[i].SetQuantity(0);
//			}
//
//			found = true;
//			break;
//		}
//	}
//	if (!found) {
//		std::cout << "Item not found in cart. Nothing modified.\n";
//	}
//}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
	bool found = false;
	for (size_t i = 0; i < cartItems.size(); i++) {
		if (cartItems[i].GetName() == item.GetName()) {
			cartItems[i].SetDescription(item.GetDescription());
			cartItems[i].SetPrice(item.GetPrice());
			cartItems[i].SetQuantity(item.GetQuantity());

			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "Item not found in cart. Nothing modified.";
	}
}

int ShoppingCart::GetNumItemsInCart() const {
	return cartItems.size();
}

int ShoppingCart::GetCostOfCart() const {
	int sumOfCart = 0;
	for (size_t i = 0; i < cartItems.size(); i++) {

		sumOfCart += (cartItems[i].GetPrice() * cartItems[i].GetQuantity());
		
	}

	return sumOfCart;
}

void ShoppingCart::PrintTotal() const {

	int itemsInCart = 0;
	for (size_t i = 0; i < cartItems.size(); i++) {
		itemsInCart += cartItems[i].GetQuantity();
	}

	std::cout << this->GetCustomerName() << "'s Shopping Cart - " << this->GetDate() << endl;
	std::cout << "Number of Items: " << itemsInCart << endl;
	std::cout << endl;

	for (size_t i = 0; i < cartItems.size(); i++) {
		cartItems[i].PrintItemCost();
	}

	if (cartItems.size() == 0) {
		std::cout << "SHOPPING CART IS EMPTY" << endl;
	}

	std::cout << endl;
	std::cout << "Total: $" << this->GetCostOfCart(); //double check this endl 
}

void ShoppingCart::PrintDescriptions() const {
	std::cout << this->GetCustomerName() << "'s Shopping Cart - " << this->GetDate() << endl;
	std::cout << endl;
	std::cout << "Item Descriptions" << endl;
	for (size_t i = 0; i < cartItems.size(); i++) {
		cartItems[i].PrintItemDescription();
	}
	//cout << endl;
}

vector<ItemToPurchase>& ShoppingCart::GetCartItems() {
	return cartItems;
}
