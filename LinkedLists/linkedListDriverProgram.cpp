#include <iostream>
#include "linkedlist.h"

int main(){

	int choice, element;

	do{
		
		cout<<"\n\t1: Insert at beginning of list\n\t\n\t2: Insert at end of list\n\t\n\t3: Insert at position 'n' of list\n\t\n\t4: Display linkedList\n\t\n\t5: Delete from start of list\n\t\n\t6: Delete from end of list\n\t\n\t7: Delete from position n\n\t\n\t8: Return data at position n\n\t\n\t9: Maximum value\n\t\n\t10: Minimum value\n\t\n\t0: Exit"<<endl;
		cin>>choice;
		switch(choice){
			case 0:
				break;

			case 1:
				cout<<"Enter element:\t";
				cin>>element;
				insertBegin(element);
				break;
			case 2:
				cout<<"Enter element:\t";
				cin>>element;
				insertEnd(element);
				break;
			case 3:
				cout<<"Enter element:\t";
				cin>>element;
				int position;
				cout<<"Enter position (starting from 1):\t";
				cin>>position;
				insertAtPosition(element,position);
				break;
			case 4:
				displayList();
				break;
			case 5:
				deleteFromBeginning();
				break;
			case 6:
				deleteFromEnd();
				break;
			case 7:
				int pos;
				cout<<"Enter position (starting from 1):\t";
				cin>>pos;
				deleteFromPosition(pos);
				break;
			case 8:
				cout<<"Enter position (starting from 1):\t";
				cin>>pos;
				cout<< at(pos)->data;
				break;
			case 9:
					if(max() == NULL){
					cout<<"\tList empty\n";
				}
				cout<< max()->data;
				break;
			case 10:
				if(min() == NULL){
					cout<<"\tList empty\n";
				}
				cout<< min()->data;
				break;
			default:
				cout<<"\n Illegal choice \n";
				break;
		}
	}while(choice!=0);
	
	
	return 0;
}
