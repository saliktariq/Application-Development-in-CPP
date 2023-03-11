#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkBalance(string s) {
    stack<char> stack;
    for (char bracket : s) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            stack.push(bracket);
        } else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if ((bracket == ')' && top != '(') ||
                (bracket == ']' && top != '[') ||
                (bracket == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    string s = "{{(})}";
    if (checkBalance(s)) {
        cout << "The brackets in " << s << " are balanced.\n";
    } else {
        cout << "The brackets in " << s << " are not balanced.\n";
    }
    return 0;
}

