#include<bits/stdc++.h>
#include<iostream>
#include<vector>

int main() {

	std::vector<int> arr1,arr2;
	
	for(int i=0;i<2;i++) {
		int val =0;
		std::cin>>val;
		arr1.push_back(val);
	}

	for(int i=0;i<2;i++) {
		int val = 0;
		std::cin>>val;
		arr2.push_back(val);
	}

	std::cout<<"\n Size of arr1 : "<<arr1.size();
	std::cout<<"\n Size of arr2 : "<<arr2.size();

	int length = arr1.size()+arr2.size();
	int devider = 1;
	if(length%2 == 0){
		devider = 2;
	}

	std::vector<int> mergedArr;


	int i=0;
	int j=0;
	while(i<arr1.size() && j<arr2.size()){
		if(arr1[i]>arr2[j]){
			mergedArr.push_back(arr2[j]);
			j++;
		} else {
			mergedArr.push_back(arr1[i]);
			i++;
		}	
	}
	while(i<arr1.size()) {
		mergedArr.push_back(arr1[i]);
		i++;
	}
	while(j<arr2.size()) {
		mergedArr.push_back(arr2[j]);
		j++;
	}

	/*for(int i=0;i<mergedArr.size();i++) {
		std::cout<<"\t"<<mergedArr[i];
	}*/
	std::cout<<"\n Devider: "<<devider;

	double result = 0;
	if(devider == 2) {
		result = ((double)mergedArr[length/2-1]+(double)mergedArr[length/2])/2;
	}else{
		result = mergedArr[length/2];
	}

	std::cout<<"\n Result: "<<result;


	return 0;
}
	


