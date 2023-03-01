#include <iostream>
#include "productlist.h"
#include <windows.h>

using namespace std;

int main(){
	//Setting some colours to terminal
	HANDLE myConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(myConsole,2);
	system("cls");	
	//End of styling
	
	
	
		int choice;

	do{
		
		cout<<"\n\t1: Insert Product using push_back(Product p) function:\n\t\n\t2: Delete from the end of list:\n\t\n\t";
		cout<<"3: Display product by PID:\n\t\n\t4: Calculate total price of all products:\n\t\n\t";
		cout<<"5: Sort products by category\n\t\n\t6: Sort products by price\n\t\n\t7: List all products\n\t\n\t";
		cout<<"0: Exit"<<endl;
		cout<<"\n\t";
		cin>>choice;
		switch(choice){
			case 0:
				break;

			case 1:
				{
				string productname;
				int price, category;
				cout<<"Enter product name:\t";
				cin>>productname;
				cout<<"Enter product price:\t";
				cin>>price;
				cout<<"Enter product category:\t";
				cin>>category;
				Product *product = new Product();
				product->pid = pid;
				product->pname = productname;
				product->price = price;
				product->category = category;
				push_back(product);
				break;
				}

				
			case 2:
				{
				
				cout<< pop_back();
				break;
				}

			case 3:
				{
				int product_id;
				cout<<"Enter PID (product ID):\t";
				cin>>product_id;
				displayProduct(product_id);
				break;	
				}

			case 4:

				cout << "Total price for all products:\t" << calculateTotalPrice();
				break;
			case 5:
				sortProductByCategory();
				break;
			case 6:
				sortProductByPrice();
				break;
				
			case 7: 
			{
				listAllProducts(); break;
			}
		
			default:
				
				cout<<"\n Illegal choice \n";
				break;
		}
	}while(choice!=0);
	
	
	return 0;
}

