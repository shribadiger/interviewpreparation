/*
 * Function to evaluate string to Integer
 */
#include<iostream>
#include<string>
#include<math.h>

int MAX_INT =pow(2,31)-1;

int main() {
	std::string input;
	std::cin>>input;
        int retValue=0;
	std::cout<<"\n Input: "<<input;
	bool isFirstIndexNegative = false;
	bool isBeginingSpaceEnded = false;
	for(auto i=0;i<input.size();i++) {
		if(input[i] == ' '&& isBeginingSpaceEnded == false) {
			continue;
                }
		else if(input[i]== '-' && isFirstIndexNegative==false) {
			isBeginingSpaceEnded = true;
			isFirstIndexNegative = true;
		}
		else if(input[i]==49 ||
		   input[i]==50||
		   input[i]==51 ||
		   input[i]==52 ||
		   input[i]==53 ||
		   input[i]==54 ||
		   input[i]==55 ||
		   input[i]==56 ||
		   input[i]==57 ||
		   input[i]==58) {
			isBeginingSpaceEnded = true;
			isFirstIndexNegative = true;
			int value = (int)input[i]-48;
			int multi = 10*retValue;
			retValue = multi+value;
		}
		else {
			std::cout<<"\n Zero\n";
			return 0;
		}
	}
	std::cout<<"\n Result: "<<retValue;
	return 0;
}

