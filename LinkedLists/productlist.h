#include <iostream>
using namespace std;

struct Product {
	int pid;
	string pname;
	int price;
	int category;
	struct Product *next;
};

Product *head = NULL;
int count = 0;
int pid = 100;

void push_back(Product *product){
	if(head == NULL){
		head = product;
	} else {
		Product *lastProduct = head;
		while(lastProduct->next != NULL){
			lastProduct = lastProduct->next;
		}
		lastProduct->next = product;
	}
	count++;
	pid++;
}

Product* pop_back(){
	
	    if (head == NULL) {
        cout << "Product list is empty" << endl;
        return NULL;
    }
    Product* tempProduct = head;
    Product* previousProduct = NULL;
    while (tempProduct->next != NULL) {
        previousProduct = tempProduct;
        tempProduct = tempProduct->next;
    }
    if (previousProduct == NULL) {
        head = NULL;
    } else {
        previousProduct->next = NULL;
    }
     count--;
     			cout<<"***************\n";
     			cout<<"DELETED PRODUCT\n";
     			cout<<"***************\n";
			cout<<"PID:\t\t"<<tempProduct->pid<<"\n"<<"Product name:\t"<<tempProduct->pname<<"\n"<<"Product price:\t"<<tempProduct->price<<"\n"<<"Category:\t"<<tempProduct->category<<"\n";
			cout<<"***************\n\n";
   // cout<<"Deleting: "<< tempProduct->pname;
   return tempProduct;
  //  delete tempProduct;
   
	
}

void displayProduct(int pid){
	bool found = false;
	if(head == NULL){
		cout<<"\n No product to display, Product list is empty\n";
	} else{
		
		for(Product *p = head; p!=NULL; p=p->next){
			if(p->pid == pid){
				cout<<"***************\n";
     			cout<<"REQUESTED PRODUCT\n";
     			cout<<"***************\n";
			cout<<"PID:\t\t"<<p->pid<<"\n"<<"Product name:\t"<<p->pname<<"\n"<<"Product price:\t"<<p->price<<"\n"<<"Category:\t"<<p->category<<"\n";
			cout<<"***************\n\n";
			found = true;
			}
		}
		
	}
	
	if(!found){
		cout<<"\n No product found with this PID\n";
	}
}

int calculateTotalPrice(){
	int totalPrice = 0;
	if (head == NULL){
		cout<<"\nProduct list is empty\n";
		return -1;
	} else {
			for(Product *p = head; p!=NULL; p=p->next){
				totalPrice += p->price;
			}
		}	
		return totalPrice;
	}
	


void sortProductByCategory(){
	if(head == NULL){
		cout <<"Product List Empty\n";
	} else {
		Product *tempProduct;
		bool swapped;
		do {
			swapped = false;
			for(Product *p = head; p->next != NULL; p = p->next){
				if(p->category > p->next->category){
					tempProduct = p;
					p = p->next;
					tempProduct->next = p->next;
					p->next = tempProduct;
					swapped = true;
				}
			}
		} while(swapped);
		cout<<"Products sorted by category\n";
	}
}

void sortProductByPrice(){
	if(head == NULL){
		cout <<"Product List Empty\n";
	} else {
		Product *tempProduct;
		bool swapped;
		do {
			swapped = false;
			for(Product *p = head; p->next != NULL; p = p->next){
				if(p->price > p->next->price){
					tempProduct = p;
					p = p->next;
					tempProduct->next = p->next;
					p->next = tempProduct;
					swapped = true;
				}
			}
		} while(swapped);
		cout<<"Products sorted by price\n";
	}
}


void listAllProducts(){
	
		if(head == NULL){
		cout <<"Product List Empty\n";
	} else {
		
		for(Product *p = head; p!=NULL; p=p->next){
			cout<<"***************\n";
			cout<<"PID:\t\t"<<p->pid<<"\n"<<"Product name:\t"<<p->pname<<"\n"<<"Product price:\t"<<p->price<<"\n"<<"Category:\t"<<p->category<<"\n";
			cout<<"***************\n\n";
		}
	}
	
}
