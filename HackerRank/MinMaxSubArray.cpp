#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	int numOfElements = 0;
	std::cin>>numOfElements;

	int numOfPairs = 0;
	std::cin>>numOfPairs;

	std::vector<int> elements(numOfElements,0);

	for(int i=0;i<numOfElements; i++) {
		std::cin>>elements[i];
	}

	std::sort(elements.begin(), elements.end());

	int minDiff = elements[numOfElements-1] - elements[0];
	
	std::cout<<minDiff;


	return 0;
}


