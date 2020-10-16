#include<iostream>
#include<vector>
using namespace std;
int maxLen=0;
int main() {

	int m, n;
	cin>>m>>n;
	cout<<"\n m : "<<m<<" n : "<<n;
	maxLen =  m > n ? m:n;

	cout<<"\n Max Length : "<<maxLen;
        
	int result[maxLen+1][maxLen+1]={{0}};

	for(int i=0;i<n;i++) {
		result[i][0]=1;
	}

	for(int j=0;j<n;j++) {
		result[j][j]=1;
	}

        for(int i=0;i<maxLen;i++) {
		for(int j=0;j<maxLen;j++) {
			cout<<"\t"<<result[i][j];
		}
		cout<<endl;
	}
	return 0;

}
