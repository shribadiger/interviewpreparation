#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string str="()(())((";
	int len=str.length();
	vector<char> stack(len,0);
	int top = -1;
        int validPairCount = 0;
	//push the first value
	top++;
	stack[top]=str[0];
	for(int i=1; i<len; i++) {
		if(str[i] == '(') {
			top++;
			stack[top]=str[i];
		} 
		else if( str[i] == ')' && top >=0) {
			if(stack[top] == '(') {
				validPairCount = validPairCount+2;
				stack[top]=0;
				top--;
			}
		}
		else {
			//TODO: no need to put into stack - let decide based on condition
		}
	}

	cout<<"\n top : "<<top;
	cout<<"\n result : "<<validPairCount;
	return 0;
}

