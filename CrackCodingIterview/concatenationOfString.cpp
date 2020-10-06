#include<iostream>
#include<string>

std::string concatStr(std::string words[], int length) {
	std::string resultStr;
	for(int i=0;i<length;i++) {
		//resultStr=resultStr+" "+words[i];
		resultStr.append(" ");
		resultStr.append(words[i]);
	}
	return resultStr;
}

int main() {
	std::string words[]={"shrikant","shruti","Gauthami"};
	std::string resultStr = concatStr(words,3);
	std::cout<<"\n Final Result String : "<<resultStr<<"\n";
	return 0;
}
