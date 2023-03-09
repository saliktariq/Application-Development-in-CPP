#include <iostream>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;

// Constructors
ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016") {}

ShoppingCart::ShoppingCart(string customerName, string currentDate) : customerName(customerName), currentDate(currentDate) {}

// Getters and Setters
string ShoppingCart::GetCustomerName() const {
return customerName;
}

string ShoppingCart::GetDate() const {
return currentDate;
}

// Member functions
void ShoppingCart::AddItem(ItemToPurchase item) {
cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name) {
bool found = false;
for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
if (it->GetName() == name) {
cartItems.erase(it);
found = true;
break;
}
}
if (!found) {
cout << "Item not found in cart. Nothing removed." << endl;
}
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
bool found = false;
for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
if (it->GetName() == item.GetName()) {
if (item.GetDescription() != "") {
it->SetDescription(item.GetDescription());
}
if (item.GetPrice() != 0) {
it->SetPrice(item.GetPrice());
}
if (item.GetQuantity() != 0) {
it->SetQuantity(item.GetQuantity());
}
found = true;
break;
}
}
if (!found) {
cout << "Item not found in cart. Nothing modified." << endl;
}
}

int ShoppingCart::GetNumItemsInCart() const {
int numItems = 0;
for (const auto& item : cartItems) {
numItems += item.GetQuantity();
}
return numItems;
}

int ShoppingCart::GetCostOfCart() const {
int totalCost = 0;
for (const auto& item : cartItems) {
totalCost += item.GetPrice() * item.GetQuantity();
}
return totalCost;
}

int ShoppingCart::PrintTotal() const {

cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
cout << "Number of Items: " << GetNumItemsInCart() << endl;
if (cartItems.empty()) {
cout << "\nSHOPPING CART IS EMPTY" << endl;
cout << "\nTotal: $0" << endl;
return 0;
}
else {
for (const auto& item : cartItems) {
item.PrintItemCost();
}
cout << "\nTotal: $" << GetCostOfCart() << endl;
return GetCostOfCart();
}

}

void ShoppingCart::PrintDescriptions() const {
cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl << endl;
cout << "Item Descriptions" << endl;
for (const auto& item : cartItems) {
item.PrintItemDescription();
}
}
