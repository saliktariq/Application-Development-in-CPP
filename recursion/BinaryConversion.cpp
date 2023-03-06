#include <iostream>

using namespace std;

void convertToBinary(int n) {
    if (n == 0) {
        return;
    }
    
    convertToBinary(n / 2);
    cout << n % 2;
}

int main() {
    int n = 10;
    cout << "Number in decimal base: " << n << endl;
    cout << "Number in binary base: ";
    convertToBinary(n);
    cout << endl;
    return 0;
}
