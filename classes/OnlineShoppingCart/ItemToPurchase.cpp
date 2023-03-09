#include <iostream>
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase(): itemName("none"), itemPrice(0), itemQuantity(0){}
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){
		this->itemName = name;
		this->itemPrice = price;
		this->itemQuantity = quantity;
		this->itemDescription = description;
}

string ItemToPurchase::GetName() const{
return this->itemName;
}

void ItemToPurchase::SetName(string name){
	this->itemName = name;
}

int ItemToPurchase::GetPrice() const{
	return this->itemPrice;
}

void ItemToPurchase::SetPrice(int price){
	this->itemPrice = price;
}

int ItemToPurchase::GetQuantity() const{
	return this->itemQuantity;
}

void ItemToPurchase::SetQuantity(int quantity){
	this->itemQuantity = quantity;
}

string ItemToPurchase::GetDescription() const{
	return this->itemDescription;
}

void ItemToPurchase::SetDescription(string description){
	this->itemDescription = description;
}


