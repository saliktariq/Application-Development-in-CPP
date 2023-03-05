#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int generateRandomNumber(int minVal, int maxVal){
    return rand() % (maxVal - minVal + 1) + minVal;
}

void bubbleSort(int inputArray[], int n){
	
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n-1-i; j++){
			if(inputArray[j] > inputArray[j+1]){
				int temp = inputArray[j];
				inputArray[j] = inputArray[j+1];
				inputArray[j+1] = temp;
			}
		}
	}	
}

int main(){

	std::srand(std::time(nullptr));
	int arrayA[10];
	for(int i = 0; i < 10; i++){
		arrayA[i] = generateRandomNumber(1,101);
	}
	cout << "Unsorted Array: [ ";
	for(int a: arrayA){
		cout << a << " ";
	}
	cout << "]\n\n";
	
	int n = sizeof(arrayA) / sizeof(arrayA[0]);
	
	bubbleSort(arrayA, n);
	
		cout << "Sorted Array: [ ";
	for(int b: arrayA){
		cout << b << " ";
	}
	cout << "]\n\n";
	
	return 0;
}
