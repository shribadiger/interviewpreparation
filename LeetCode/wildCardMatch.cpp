#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string input;
	string pattern;
	cin>>input;
	cin>>pattern;

	int inputLen = input.size();
	int patternLen = pattern.size();

	// DP vector for solution
	vector<vector<bool>> DP(inputLen+1, vector<bool>(patternLen+1,0));

	DP[0][0]=1;

	//step 1: fill the first row as reference with empty string
	for(int i=1; i<=patternLen;i++) {
		if(pattern[i-1]=='*' && DP[0][i-1] == 1) {
			DP[0][i]=1;
		}
	}

	//step 2: check and fill the table
	for(int i=1; i<=inputLen; i++) {
		for(int j=1;j<=patternLen; j++) {
			if((input[i-1] == pattern[j-1]) || (pattern[j-1] == '?') ) {
				DP[i][j]=DP[i-1][j-1];
			}
			else if(pattern[j-1] == '*') {
				DP[i][j]=(DP[i-1][j] || DP[i][j-1]);
			}
		}
	}


	for(int i=0; i<=inputLen;i++) {
		for(int j=0; j<=patternLen;j++) {
			cout<<"\t"<<DP[i][j];
		}
		cout<<"\n";
	}

	cout<<"\n Pattern Match result : "<<DP[inputLen][patternLen];

	return 0;
}
