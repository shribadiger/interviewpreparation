/*
 * code check the given string is permutation of another string
 */
#include<iostream>
#include<string>

bool isPermutationOfString(std::string str1, std::string str2) {

	int charCheckList[26]={0};
	for(int i=0;i<str1.length();i++) {
		charCheckList[str1[i]-'a']++;
	}
	for(int i=0;i<str2.length();i++) {
		charCheckList[str2[i]-'a']++;
	}

	for(int i=0;i<str1.length();i++) {
		if(charCheckList[str1[i]-'a']%2 != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	std::string str1,str2;
	std::cin>>str1>>str2;

	if(isPermutationOfString(str1,str2)) {
		std::cout<<"\n Yes";
	}
	else {
		std::cout<<"\n No";
	}
	return 0;
}
