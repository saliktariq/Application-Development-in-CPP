#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void toggleCase(string& s, int strLength) {
    if (strLength == 0) {
        return;
    }
    if (isalpha(s.at(strLength - 1))) {
        if (isupper(s.at(strLength - 1))) {
            s.at(strLength - 1) = tolower(s.at(strLength - 1));
        } else {
            s.at(strLength - 1) = toupper(s.at(strLength - 1));
        }
    }
    return toggleCase(s, strLength - 1);
}

int main() {
    string s = "UPPERCASE.lowercase@";
    cout << "Original String: " << s << endl;
    toggleCase(s, s.length());
    cout << "Modified String: " << s << endl;
}

