/*
 * adavnce program , first attempt
 */
#include<iostream>
#include<string>
#include<map>

int main() {
	std::string input;
	std::cin>>input;
	int length = input.length();

	int unusedCharList[26]={0};
	int usedCharList[26]={0};
	int requiredCharList[26]={0};

	for(int i=0;i<input.length();i++){
		unusedCharList[input[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		requiredCharList[i]=unusedCharList[i]/2;
	}

	char result[100000];
        int j = 0;
	//iteration start here
	char ch = input[length-1];
	int relPosition = ch -'a';

	//add first char from last char
	result[j++]=ch;
	unusedCharList[relPosition]--;
	usedCharList[relPosition]++;

	//for remaining strings
	for(int i = length-2; i>=0;i--){
		ch = input[i];
		relPosition=ch-'a';

		if(usedCharList[relPosition] < requiredCharList[relPosition]){
			if(ch>result[j-1]){
				result[j++]=ch;
				unusedCharList[relPosition]--;
				usedCharList[relPosition]++;
			} else {
				while(j>0 && ch < result[j-1] && (usedCharList[result[j-1] -'a']-1 + unusedCharList[result[j-1]-'a']) >= requiredCharList[result[j-1]-'a']){
					usedCharList[result[--j]-'a']--;
				}
				result[j++]=ch;
				unusedCharList[relPosition]--;
				usedCharList[relPosition]++;
			}
				
		}
		else {
			unusedCharList[relPosition]--;
		}

	}

	for(int i=0;i<length/2;i++) {
		std::cout<<result[i];
	}

	return 0;
}


		
