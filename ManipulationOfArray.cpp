#include<iostream>
#include<vector>
using namespace std;

void printResult(std::vector<long long> result,int n){
	for(int i=0;i<n;i++) {
		std::cout<<"\t"<<result[i];
	}
}

int main() {
	int n=10;
	int m=3;

	std::vector<long long> result(n,0);
	while(m>0) {
		int a = 0;
		int b = 0;
		int k = 0;
		cin>>a>>b>>k;
		a--;
		result[a]=result[a]+k;
		result[b]=result[b]-k;
		printResult(result,n);
		m--;
	}

	return 0;
}
