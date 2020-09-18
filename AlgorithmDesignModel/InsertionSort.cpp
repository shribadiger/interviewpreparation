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
		for(int j=i;j>0;j--) {
			//compare and swap the elements
			if(Array[j]<Array[j-1]){
				int temp = Array[j];
				Array[j]=Array[j-1];
				Array[j-1]=temp;
			}
		}
	}
	PrintArray(Array,9);


	return 0;
}

