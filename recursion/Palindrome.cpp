#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string myString) {
    if (myString.length() <= 1) {
        return true;
    }
    int start = 0;
    int end = myString.length() - 1;
    if (myString.at(start) != myString.at(end)) {
        return false;
    } else {
        return isPalindrome(myString.substr(start + 1, end - 1));
    }
}

int main() {
    string s = "aba";
    cout << s << endl;
    cout << "Is it a Palindrome? :" << isPalindrome(s) << endl;
    
    string s2 = "salik";
    cout << s2 << endl;
    cout << "Is it a Palindrome? :" << isPalindrome(s2) << endl;
    
    return 0;
}

