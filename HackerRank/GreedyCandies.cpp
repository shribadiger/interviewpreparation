#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArr(std::vector<int> Arr) {
	for(int i=0;i<Arr.size();i++) {
		std::cout<<"\t"<<Arr[i];
	}
	std::cout<<std::endl;
}

int main() {
	int size;
	cin>>size;
	vector<int> Arr;
	for(int i=0; i<size; i++) {
		int input;
		cin>>input;
		Arr.push_back(input);
	}

	std::cout<<"\n Input Array :\n";
	printArr(Arr);

	std::vector<int> LeftOrder(size,0);
	std::vector<int> RightOrder(size,0);
	LeftOrder[0]=1;
	for(int i=1;i<size;i++)	{
		if(Arr[i]>Arr[i-1]) {
			LeftOrder[i]=LeftOrder[i-1]+1;
		} else {
			LeftOrder[i]=1;
		}
	}

	std::cout<<"\nLeft Array: \n";
	printArr(LeftOrder);

	RightOrder[size-1]=1;
	for(int i=size-2;i>=0;i--) {
		if(Arr[i]>Arr[i+1]) {
			RightOrder[i]=RightOrder[i+1]+1;
		} else {
			RightOrder[i]=1;
		}
	}

	std::cout<<"\nRight Array: \n";
	printArr(RightOrder);

	//Now, collect the max value from each of array
	int result = 0;
	for(int i=0;i<size;i++) {
		result=result+max(LeftOrder[i],RightOrder[i]);
        }

	cout<<result;

	return 0;
}
	
