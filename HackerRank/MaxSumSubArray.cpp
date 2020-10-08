#include<iostream>
#include<vector>
using namespace std;

int main() {
	int length;
	cin>>length;
	vector<int> data(0,length);
	for(int i=0; i<length; i++) {
		int input;
		cin>>input;
		vector.push_back(input);
	}

	int combinations = 0;
	int globSum = 0;
	while(combinations < length) {
	{	int sum = globSum;
		for(int i=combinations; i<length; i++) {
			sum=globSum+data[i];
			for(int j=i+1; j<length;j++) {
				std::cout<<"\t"<<sum<<"+"<<data[j];
			}
			std::cout<<"\n";
		}
		globSum=globSum+data[combinations];
		comninations++;
		std::cout<<"\n";
			
	}
	std::cout<<"\n"<<globSum;
	return 0;
}
