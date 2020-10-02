/*
 * Algorithm to find the longest palindrome 
 */
#include<bits/stdc++.h>
//check fromt the string middle varify whether is is pallindrom or not
int palindromCheck(std::string str, int left, int right) {
	if(str.length()==0 && str == "" && left>right) {
		return 0;
	}

	while(left>=0 && right<str.length() && str.at(left)==str.at(right)){
		left--;
		right++;
	}

	return right-left;
}

int main() {
	std::string str="raceracer";

	//check whether given string is empty
	if(str.length() == 0) {
		std::cout<<"\n Empty string";
		return 0;
	}

	int start = 0;
	int end = 0;

	for(int i=0;i<str.length();i++){
		int len1 =  palindromCheck(str,i,i);
		int len2 =  palindromCheck(str,i,i+1);
		int len = std::max(len1,len2);
		if(len > end-start){
			start = i-((len-1)/2);
			end = i+(len/2);
		}
	}
	std::cout<<str.substr(start,end+1);

	return 0;
}

