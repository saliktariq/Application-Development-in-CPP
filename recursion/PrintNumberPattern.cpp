#include <iostream>

using namespace std;

void PrintNumPattern(int n, int m) {

if(n < 0){
	cout << n << "\t";
	return;
}
cout << n << "\t";

PrintNumPattern(n-m, m);
cout<<n<<"\t";
}


int main() {
   int num1;
   int num2;

   cin >> num1;
   cin >> num2;
   PrintNumPattern(num1, num2);
   
   return 0;
}
