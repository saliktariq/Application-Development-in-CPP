#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int generateRandomNumber(int minVal, int maxVal){
    return rand() % (maxVal - minVal + 1) + minVal;
}

void mergeDown(int arrayLeft[], int sizeLeft, int arrayRight[], int sizeRight, int arrayOriginal[], int sizeOriginal){
	
	int i = 0; // marker for arrayLeft
	int j = 0; // marker for arrayRight
	int k = 0; //marker for arrayOriginal
	
	while(i < sizeLeft && j < sizeRight){
		if(arrayLeft[i] < arrayRight[j]){
			arrayOriginal[k] = arrayLeft[i];
			i++;
			k++;
		} else {
			arrayOriginal[k] = arrayRight[j];
			j++;
			k++;
		}
	}
	
	while(i < sizeLeft){
		arrayOriginal[k] = arrayLeft[i];
		i++;
		k++;
	}

	
	while(j < sizeRight){
		arrayOriginal[k] = arrayRight[j];
		j++;
		k++;
	}
	
}

void mergeSort(int inputArray[], int n){
	if(n < 2){
		return;
	}
	
	int nL = n % 2 == 0 ? n / 2: n / 2 + 1;
	int nR = n - nL;
	
	int arrayL[nL];
	
	for(int i=0; i < nL; i++){
		arrayL[i] = inputArray[i];
	}
	int arrayR[nR];
	
	for(int j = 0; j < nR + 1; j++){
		arrayR[j] = inputArray[j + nL];
	}
	
	mergeSort(arrayL, nL);
	mergeSort(arrayR, nR);
	mergeDown(arrayL, nL, arrayR, nR, inputArray, n);
	
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
	
	mergeSort(arrayA, n);
	
		cout << "Sorted Array: [ ";
	for(int b: arrayA){
		cout << b << " ";
	}
	cout << "]\n\n";
	
	return 0;
}
