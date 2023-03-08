#include <iostream>

using namespace std;

void recursion(int i){

			int array[10];
	cout << i << endl;
	i++;
	recursion(i);
	
	

		


}


int main() {
	
	recursion(0);
}
