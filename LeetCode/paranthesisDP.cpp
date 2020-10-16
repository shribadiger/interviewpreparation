#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string str;
	cin>>str;

	int len = str.length();

	vector<int> longest(len,0);
	int ans = 0;

	for(int i=1;i<len;i++) {
		//if string has "(" need to insert zero.. that I did in initialization
		if(str[i] == ')') {
			if(str[i-1] == '(') //check the previous char has any matach with currect closing brace
			{
				int prevValue = i>=2 ? longest[i-2]:0;
				longest[i]=prevValue+2; //checking the previous closing parenthesis value
			} else {
				// if condition here previous index(i-1) also has ')' then
				// check the ith length - previous valid parath length - 1 ( :. -1 - bcz index start from zero)
				if( (i-longest[i-1]-1) >= 0 && str[i-longest[i-1]-1] == ')') {
					//longest[i] = (previous index matching pair count +2) + ( whole string valid count)
					int prevIndexValue = longest[i-1];
					int wholeValidMatchValue = (i-longest[i-1])>=2 ? longest[i-longest[i-1]-2]:0;
					longest[i]= prevIndexValue + wholeValidMatchValue + 2; // 2 for current match
				}
			}
		}
		//Take the maximum value as logest match
		ans = max(ans, longest[i]);
	}
	cout<<"\n Result: "<<ans;
}

