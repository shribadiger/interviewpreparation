#include<iostream>
#include<string>
#include<bits/stdc++.h>

int main() {

	std::string str="   ";

	int charCheck[1000]={0};

	int result = 0;
	int longStrLen = 0;

	//Repeat the length each charectors
	for(int i=0;i<str.length();i++){
		int itr = i;
		int index = str[itr];
		while(charCheck[index]<1 && itr<str.length()){
			charCheck[index]++;
			longStrLen++;
			itr++;
		        index = str[itr];
		}
		if(itr>=str.length()){
			//no char repeated and breack the loop
			result=result>longStrLen?result:longStrLen;
			break;
		}
		result=result>longStrLen?result:longStrLen;
		longStrLen=0;
		memset(charCheck,0,sizeof(charCheck));
	}

	std::cout<<"\n Result : "<<result;
	return 0;
}
