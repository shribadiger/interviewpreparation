#include<bits/stdc++.h>
#include<vector>

int main() {
	int totalCost = 0;
	int numOfFlavors = 0;

	std::cin>>totalCost>>numOfFlavors;

	//declare the container to hold price
	std::vector<long> price(numOfFlavors,0);
	for(int i=0;i<numOfFlavors;i++) {
		std::cin>>price[i];
	}

	//I need two output firstIndex and secondIndex
	//int firstIndex = -1;
	//int secondIndex = -1;
	int i = 0;
	int j = 0;
	bool resultFound = false;

	for(int i=0;i<numOfFlavors;i++) {
		long remAmount = totalCost - price[i];
		for(j=0; j<numOfFlavors && j!=i;j++){
			if(remAmount == price[j]){
				resultFound = true;
				break;
			}

		}
		if(resultFound){
			std::cout<<j+1<<" "<<i+1;
			break;
		}
	}

	return 0;
}


	
