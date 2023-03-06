#include <iostream>

using namespace std;

int sumOfOddDigits(int n){
	if (n==0){
		return 0;
	} else {
		int endDigit = n % 10;
		if(endDigit % 2 == 1){
			return endDigit + sumOfOddDigits( n / 10);
		} else {
			return sumOfOddDigits( n / 10);
		}
	}
	
		
	}

int main(){
	
	int n = 987654321;
	
	cout << sumOfOddDigits(n);
	
	return 0;
}
