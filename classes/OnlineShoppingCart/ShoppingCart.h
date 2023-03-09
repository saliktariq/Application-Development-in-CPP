#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart{
	private:
		string customerName = "none";
		string currentDate = "January 1, 2016";
		vector<ItemToPurchase> cartItems;
		
	public:
		//Getters and Setters
		string GetCustomerName() const;
		string GetDate() const;
		
		//Constructors
		ShoppingCart();
		ShoppingCart(string customerName, string currentDate);

		
		//Member functions
		void AddItem(ItemToPurchase item);
		void RemoveItem(string name);
		void ModifyItem(ItemToPurchase item);
		int GetNumItemsInCart() const;
		int GetCostOfCart() const;
		int PrintTotal() const;
		void PrintDescriptions()const;

		
		
		
		
};


#endif
