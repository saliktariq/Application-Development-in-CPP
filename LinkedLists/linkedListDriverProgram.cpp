#include <iostream>
#include "linkedlist.h"
#include <windows.h>

int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
	 FOREGROUND_GREEN | BACKGROUND_RED);
	system("cls");	
	int choice, element;

	do{
		
		cout<<"\n\t1: Insert at beginning of list\n\t\n\t2: Insert at end of list\n\t\n\t";
		cout<<"3: Insert at position 'n' of list\n\t\n\t4: Display linkedList\n\t\n\t";
		cout<<"5: Delete from start of list\n\t\n\t6: Delete from end of list\n\t\n\t";
		cout<<"7: Delete from position n\n\t\n\t8: Return data at position n\n\t\n\t";
		cout<<"9: Maximum value\n\t\n\t10: Minimum value\n\t\n\t11: Swap Alternative Nodes\n\t\n\t12: Sort between start and end positions\n\t\n\t0: Exit"<<endl;
		cout<<"\n\t";
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
			case 11:
				swapAlternative();
				break;
			case 12:
				int start,end;
				cout<<"Enter start position for sorting: ";
				cin>>start;
				cout<<"Enter end position for sorting (inclusive): ";
				cin>>end;
				sort(start,end);
				break;
			default:
				
				cout<<"\n Illegal choice \n";
				break;
		}
	}while(choice!=0);
	
	
	return 0;
}
