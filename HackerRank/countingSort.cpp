#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void countSort(vector<int>& Array) {
	int maxElement = *max_element(Array.begin(),Array.end());
	int minElement = *min_element(Array.begin(),Array.end());
	int range = maxElement-minElement + 1;
	cout<<"\n Max Element : "<<maxElement;
	cout<<"\n Min Element : "<<minElement;
	cout<<"\n Range       : "<<range; // Value Range identification in count list
	vector<int> count(range), Result(Array.size()); // Creating the intemediate data structure

	//Step 1: Insert countOfElement into count array
	for(int i=0;i<Array.size();i++){
		count[Array[i]-minElement]++;
	}

	//Step 2: move i to i+1 postion in count array
	for(int i=0;i<count.size()-1;i++){
		count[i+1]=count[i+1]+count[i];
	}

	//Step 3: Prepare the result array by checking the count
	//Note: we need trace array from right to left now
	for(int i=Array.size()-1; i>=0;i--){
		Result[count[Array[i]-minElement] -1] = Array[i]; // Array[i]-min --> Indicates the count element index 
		count[Array[i]-minElement]--; //Decrement the count bcz we added into result
	}	

	//Step 4: Copy the Result to Array
	for(int i=0;i<Result.size();i++)
		Array[i]=Result[i];
}

void printArray(vector<int> Array){
	cout<<"\nArray: ";
	for(int i=0;i<Array.size();i++){
		cout<<"\t"<<Array[i];
	}
	cout<<endl;
}
int main() {
	vector<int> Array = {5,6,7,7,1,1,1,3,4};
	countSort(Array);
	printArray(Array);
	return 0;
}
