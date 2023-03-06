#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void splitAlphaNumerics(string& s, int strLength, string& mystring, string& mynumber) {
    if (strLength == 0) {
        return;
    }
    
    if (isalpha(s.at(strLength - 1))) {
        mystring = s.at(strLength - 1) + mystring;
    } else if (isdigit(s.at(strLength - 1))) {
        mynumber = s.at(strLength - 1) + mynumber;
    }
	
    splitAlphaNumerics(s, strLength - 1, mystring, mynumber);
}

int main() {
    string s = "am3n45jj677";
    string mystring = "";
    string mynumber = "";
    cout << "Original String: " << s << endl;
    splitAlphaNumerics(s, s.length(), mystring, mynumber);
    cout << "String: " << mystring << endl;
    cout << "Number: " << mynumber << endl;
}

