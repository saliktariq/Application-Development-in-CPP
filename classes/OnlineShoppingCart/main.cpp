#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ItemToPurchase.cpp"


int main() {
	
	string name, price, quantity;
	cout<<"Item 1\n";
	cout<<"Enter the item name:\n";
	getline(cin,name);

	cout<<"Enter the item price:\n";
	getline(cin,price);

	cout<<"Enter the item quantity:\n";
	getline(cin,quantity);

	cout<<endl;
	cin.ignore();
	
	ItemToPurchase item1;
	item1.SetName(name);
	item1.SetPrice(stoi(price));
	item1.SetQuantity(stoi(quantity));
	
	cout<<"Item 2\n";
	cout<<"Enter the item name:\n";
	getline(cin,name);

	cout<<"Enter the item price:\n";
	getline(cin,price);

	cout<<"Enter the item quantity:\n";
	getline(cin,quantity);

	
	ItemToPurchase item2;
	item2.SetName(name);
	item2.SetPrice(stoi(price));
	item2.SetQuantity(stoi(quantity));
	
	cout<<endl;
	cout<<"TOTAL COST"<< "\n";
	cout<< item1.GetName()<<" "<<item1.GetQuantity()<<" @ $"<<item1.GetPrice()<<" = $"<<item1.GetQuantity() * item1.GetPrice() << endl;
	cout<< item2.GetName()<<" "<<item2.GetQuantity()<<" @ $"<<item2.GetPrice()<<" = $"<<item2.GetQuantity() * item2.GetPrice() << endl;
   
	cout<<endl;
	cout<<endl;
	cout<<"Total: $"<< (item1.GetQuantity() * item1.GetPrice()) + (item2.GetQuantity() * item2.GetPrice());
   
   return 0;
}
