#include<iostream>
#include<string>

int main() {
	std::string input;
	std::cin>>input;

	int charChecker[26]={0};

	for(int i=0;i<input.length();i++) {
		if(charChecker[input[i]-'a'] >0) {
			std::cout<<"\n Result: False\n";
			return 0;
		} 
		charChecker[input[i]-'a']++;
	}
	std::cout<<"\n Result: True\n";
	return 0;
}
