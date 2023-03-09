#include <iostream>
#include "ItemToPurchase.h"
#include<math.h>


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

	this->itemPrice = ceil(price);
}

int ItemToPurchase::GetQuantity() const{
	return this->itemQuantity;
}

void ItemToPurchase::SetQuantity(int quantity){
	this->itemQuantity = ceil(quantity);
}

string ItemToPurchase::GetDescription() const{
	return this->itemDescription;
}

void ItemToPurchase::SetDescription(string description){
	this->itemDescription = description;
}

void ItemToPurchase::PrintItemCost() const{
	cout<< this->GetName()<<" "<<this->GetQuantity()<<" @ $"<<this->GetPrice()<<" = $"<<this->GetQuantity() * this->GetPrice() << endl;
}
void ItemToPurchase::PrintItemDescription() const{
	cout<< this->GetName()<<": "<<this->GetDescription()<< endl;
}

