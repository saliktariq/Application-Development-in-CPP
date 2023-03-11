#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

int evaluatePostfixExp(string exp);
void postFixExp(string exp);

int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    postFixExp(exp);
    return 0;
}

void postFixExp(string exp){
    stack<char> myStack;
    unordered_map<char, int> precedenceMap = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2},
        {'^', 3}
    };

    string postFix = "";
    for(int i=0; i < exp.length(); i++){
        if(isalpha(exp[i])){
            postFix += exp[i];
            continue;
        }
        if(exp[i] == '('){
            myStack.push(exp[i]);
            continue;
        }
        if(exp[i] == ')'){
            while(myStack.top() != '(') {
                postFix += myStack.top();
                myStack.pop();
            }
            myStack.pop(); 
            continue;
        }
        if (!myStack.empty() && precedenceMap[exp[i]] <= precedenceMap[myStack.top()]) {
            while (!myStack.empty() && precedenceMap[exp[i]] <= precedenceMap[myStack.top()]) {
                postFix += myStack.top();
                myStack.pop();
            }
            myStack.push(exp[i]); 
            continue;
        }
        myStack.push(exp[i]); 
    }
    while(!myStack.empty()){
        postFix+=myStack.top();
        myStack.pop();
    }
    cout << "Postfix expression: " << postFix << endl;

}
