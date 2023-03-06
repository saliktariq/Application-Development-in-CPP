#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int generateRandomNumber(int minVal, int maxVal){
    return rand() % (maxVal - minVal + 1) + minVal;
}

int partitionArray(int inputArray[], int start, int end){
    int pivotIndex = generateRandomNumber(start, end);
    int pivot = inputArray[pivotIndex];

    // Move the pivot element to the end of the subarray
    int temp = inputArray[end];
    inputArray[end] = inputArray[pivotIndex];
    inputArray[pivotIndex] = temp;

    int partitionIndex = start;
    for(int i = start; i < end; i++){
        if(inputArray[i] <= pivot){
            // Swap the current element with the element at the partition index
            temp = inputArray[i];
            inputArray[i] = inputArray[partitionIndex];
            inputArray[partitionIndex] = temp;

            partitionIndex++;
        }
    }

    // Swap the pivot element back to its final position
    temp = inputArray[end];
    inputArray[end] = inputArray[partitionIndex];
    inputArray[partitionIndex] = temp;

    return partitionIndex;
}


void quickSort(int inputArray[], int start, int end){
	
	if(start < end){
		int pIndex = partitionArray(inputArray, start, end);
		quickSort(inputArray, start, pIndex-1);
		quickSort(inputArray, pIndex+1, end);
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
	
	quickSort(arrayA, 0, n - 1);
	
		cout << "Sorted Array: \t[ ";
	for(int b: arrayA){
		cout << b << " ";
	}
	cout << "]\n\n";
	
	return 0;
}
