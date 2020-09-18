#include<iostream>
using namespace std;
//utility function to print the list
void PrintArray(int Array[],int n) {
	for(int i=0;i<n;i++){
		cout<<"\t"<<Array[i];
	}
	cout<<endl;
}

int main() {
	int Array[] = {9,8,7,6,5,4,3,2,1};
	PrintArray(Array,9);

	for(int i=0;i<9;i++) {
		int min = i;
		for(int j=i+1;j<9;j++) {
			if(Array[min] >Array[j]) {
				min=j;
			}
		}
		int temp = Array[min];
		Array[min]=Array[i];
		Array[i]=temp;
	}
	PrintArray(Array,9);


	return 0;
}

