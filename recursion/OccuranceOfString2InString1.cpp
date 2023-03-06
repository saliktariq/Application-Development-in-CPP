#include <iostream>
#include <string>

using namespace std;

int occuranceOfString2InString1(string s1, string s2){
	// Get the lengths of both strings
	int lengthOfStrings1 = s1.length();
	int lengthOfStrings2 = s2.length();
	
	// Check if s1 is shorter than s2, if so there can be no occurrence of s2 in s1
	if(lengthOfStrings1 < lengthOfStrings2){
		return 0;
	}
	
	// Check if s2 occurs at the beginning of s1
	if(s1.substr(0,lengthOfStrings2) == s2){
		// If it occurs, increment the count by 1 and make a recursive call to the function with the updated arguments
		return 1 + occuranceOfString2InString1(s1.substr(lengthOfStrings2), s2);
	} else {
		// If it does not occur, make a recursive call to the function with the first character of s1 removed and s2 unchanged
		return occuranceOfString2InString1(s1.substr(1), s2);
	}
}

int main(){
	// Define the strings to be used
	string s1 = "This is a good sentence, is not it?";
	string s2= "is";
	
	// Call the function and output the result
	cout << occuranceOfString2InString1(s1, s2);
	
	return 0;
}

