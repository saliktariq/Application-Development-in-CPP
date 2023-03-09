#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase{
	private:
		string itemName;
		int itemPrice;
		int itemQuantity;
		string itemDescription;
		
	public:
		//Getters and Setters
		string GetName() const;
		void SetName(string name);
		
		int GetPrice() const;
		void SetPrice(int price);
		
		int GetQuantity() const;
		void SetQuantity(int quantity);
		
		string GetDescription() const;
		void SetDescription(string description);
		
		//Constructors
		ItemToPurchase();
		ItemToPurchase(string name, string description, int price, int quantity);
		
		//Member functions
		void PrintItemCost() const;
		void PrintItemDescription() const;
		
		
		
		
};


#endif
