#include<iostream>
#include<vector>
using namespace std;

int main() {
	std::vector<std::vector<int>> result;
	for(int i=0;i<5;i++){
		std::vector<int> tmp(5,0);
		result.push_back(tmp);
	}

	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			cout<<"\t"<<result[i][j];
		}
		cout<<endl;
	}

	return 0;
}
