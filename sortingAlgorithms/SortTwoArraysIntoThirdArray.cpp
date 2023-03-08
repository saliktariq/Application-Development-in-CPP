#include <iostream>

using namespace std;

int* mergeTwoArrays(int arrA[], int arrB[], int sizeA, int sizeB) {
    int sizeC = sizeA + sizeB;
    int* arrC = new int[sizeC];
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (arrA[i] < arrB[j]) {
            arrC[k++] = arrA[i++];
        } else {
            arrC[k++] = arrB[j++];
        }
    }
    while (i < sizeA) {
        arrC[k++] = arrA[i++];
    }
    while (j < sizeB) {
        arrC[k++] = arrB[j++];
    }
    return arrC;
}

int main() {
    int arrA[] = { 11, 22, 33, 44, 55 };
    cout << "Array A: [ ";
    for (int i : arrA) {
        cout << i << "\t";
    }
    cout << "]" << endl;

    int arrB[] = { 12, 23, 32, 45, 42, 66, 99 };
    cout << "Array B: [ ";
    for (int i : arrB) {
        cout << i << "\t";
    }
    cout << "]" << endl;

    int sizeA = sizeof(arrA) / sizeof(arrA[0]);
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);

    int* arrC = mergeTwoArrays(arrA, arrB, sizeA, sizeB);

    cout << "Merged Array: [ ";
    for (int i = 0; i < (sizeA + sizeB); i++) {
        cout << arrC[i] << "\t";
    }
    cout << "]" << endl;

    delete[] arrC;

    return 0;
}

