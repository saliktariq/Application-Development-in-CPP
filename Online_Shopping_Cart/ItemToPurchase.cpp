#include <iostream>
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase() : itemName("none"), itemPrice(0), itemQuantity(0) {}
ItemToPurchase::ItemToPurchase(string name="none", string description="none", int price=0, int quantity=0) {
	this->itemName = name;
	this->itemPrice = price;
	this->itemQuantity = quantity;
	this->description = description;
}

string ItemToPurchase::GetName() const {
	return this->itemName;
}

void ItemToPurchase::SetName(string name) {
	this->itemName = name;
}

int ItemToPurchase::GetPrice() const {
	return this->itemPrice;
}

void ItemToPurchase::SetPrice(int price) {
	this->itemPrice = price;
}

int ItemToPurchase::GetQuantity() const {
	return this->itemQuantity;
}

void ItemToPurchase::SetQuantity(int quantity) {
	this->itemQuantity = quantity;
}

void ItemToPurchase::SetDescription(string description) {
	this->description = description;
}

void ItemToPurchase::PrintItemCost() const {
	cout << this->GetName() << " " << this->GetQuantity() << " @ $" << this->GetPrice() << " = $" << this->GetQuantity() * this->GetPrice() << endl;
}

string ItemToPurchase::GetDescription() const {
	return this->description;
}

void ItemToPurchase::PrintItemDescription() const {
	cout << this->GetName() << ": " << this->GetDescription() << endl;
}

