#include<bits/stdc++.h>
using namespace std;

int main() {
	std::string input;
	cin>>input;
	int A[26] = {0};
	for(int i=0;i<input.length();i++){
		A[(int)input[i]-'a']++;
	}
        bool isValid = false;
	for(int i=0;i<26;i++){
		if(A[i]%2==0 ||(A[i]-1)%2 == 0) {
			isValid=true;
		}
		else {
			isValid = false;
			break;
		}
	}
	isValid?std::cout<<"Yes":std::cout<<"No";
	return 0;
}
