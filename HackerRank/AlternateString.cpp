#include<bits/stdc++.h>
using namespace std;

int main()
{
	int testCases;
	cin>>testCases;
	while(testCases--){
		std::string input;
		cin>>input;
		int delCount = 0;
		int length = input.length();
		for(int i=0;i<length;i++) {
			if(input[i]==input[i+1]){
				delCount++;
			}
		}
		cout<<delCount<<"\n";
	}
	return 0;
}
