/*
 * Match the regular expression
 * aab <--> c*a*b
 */

#include<iostream>
#include<vector>
using namespace std;

void print_result(vector<vector<bool>> result) {
	int m=result.size();
	for(int i=0;i<m;i++) {
		for(int j=0; j<result[0].size();j++) {
			cout<<"\t"<<result[i][j];
		}
		cout<<"\n";
	}
}
int main() {
	string str = "aab";
	string pat = "c*a*b";

	int strLen = str.length();
	int patLen = pat.length();
	
	vector<vector<bool>> result(strLen+1, vector<bool>(patLen+1,0));

	print_result(result);

	//now prepare the dynamic program solution
	//step 1: set first index as 1
	result[0][0]=1;

	//step 2: Filling the fist row with proper values
	for(int i=1;i<patLen;i++) {
		if(pat[i]=='*' && result[0][i-2] == 1) {
			result[0][i]=1;
		}
	}

	print_result(result);

	return 0;
}
