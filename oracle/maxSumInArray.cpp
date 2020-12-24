/*
 * Use the max array sum
 */
#include<iostream>
#include<vector>
using namespace std;

int maxSumOfArray(vector<int> Array) {
	int result = 0;
	for(int i=0;i<Array.size();i++) {

		

int main() {
	int sizeOfArray;
	cin>>sizeOfArray;

	vector<int> Array;

	for(int i=0;i<sizeOfArray;i++) {
		int input=0;
		cin>>input;
		Array.push_back(input);
	}

	for(int i=0;i<sizeOfArray;i++) {
		cout<<"\t"<<Array[i];
	}

	cout<<"\n Max Sum : "<<maxSumOfArray(Array);

	return 0;
}
		
