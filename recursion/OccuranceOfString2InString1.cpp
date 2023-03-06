#include <iostream>
#include <string>

using namespace std;

int occuranceOfString2InString1(string s1, string s2){

	int lengthOfStrings1 = s1.length();
	int lengthOfStrings2 = s2.length();
	

	if(lengthOfStrings1 < lengthOfStrings2){
		return 0;
	}
	

	if(s1.substr(0,lengthOfStrings2) == s2){

		return 1 + occuranceOfString2InString1(s1.substr(lengthOfStrings2), s2);
	} else {

		return occuranceOfString2InString1(s1.substr(1), s2);
	}
}

int main(){

	string s1 = "This is a good sentence, is not it?";
	string s2= "is";
	
	cout << occuranceOfString2InString1(s1, s2);
	
	return 0;
}

