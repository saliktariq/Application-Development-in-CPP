#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main(){
	insertEnd(10);
	insertEnd(20);
	insertEnd(30);
	
	insertBegin(5);
	insertBegin(4);

	
	displayList();
	cout << max() << endl;
	cout<< min() <<endl;
	cout << at(1);
	
	printHeadToEnd();
	printEndToHead();
	deleteBack();
	displayList();
	deleteFront();
	displayList();
	
	return 0;
}
