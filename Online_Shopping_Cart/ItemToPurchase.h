#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
private:
	string itemName;
	int itemPrice;
	int itemQuantity;
	string description;

public:
	string GetName() const;
	void SetName(string name);

	int GetPrice() const;
	void SetPrice(int price);

	int GetQuantity() const;
	void SetQuantity(int quantity);

	void SetDescription(string description);
	string GetDescription() const;

	void PrintItemCost() const;
	void PrintItemDescription() const;

	ItemToPurchase();
	ItemToPurchase(string name, string description, int price, int quantity);



};


#endif