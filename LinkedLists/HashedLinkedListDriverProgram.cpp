#include <iostream>
#include "hashedlinkedlist.h"

using namespace std;
int main(){
	
	reset();
	
	insertEnd(10);
	insertEnd(20);
	insertEnd(35);
	insertEnd(47);
	
	displayParentList();
	
	
	return 0;
}
