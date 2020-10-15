#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int palindromeCheck(string input) {
	string revStr =input;
       	reverse(revStr.begin(), revStr.end());
	if(input == revStr) {
		return input.length();
	}
	return 0;
}

void largestPalindrome(string input) {
	int max=0;
	string largePalindrome;
	int n = input.length();
	for(int i=1;i<n;i++) {
		
		int result1 = palindromeCheck(input.substr(i,n-1));
		int result2 = palindromeCheck(input.substr(0,n-i));
		if(result1 && result1>max) {
			max=result1;
			largePalindrome = input.substr(i,n-1);
		}
		if(result2 && result2>max) {
			max=result2;
			largePalindrome = input.substr(0,n-i);
		}
         }
         cout<<largePalindrome;
}	
		

int main() {
	string input;
	cin>>input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	//check first given string
	string revStr = input;
	reverse(revStr.begin(),revStr.end());
	if(input ==revStr)
	{
		cout<<input;
		return 0;
	}
        
	largestPalindrome(input);
	return 0;
}
