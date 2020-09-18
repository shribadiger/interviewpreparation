#include<iostream>
using namespace std;
void printArray(int A[],int);
int partition(int A[], int low, int high)
{
	printArray(A,16);
	std::cout<<"\n Partition -- Low: "<<low<<" High: "<<high;
        int i = low;
	int pivot = A[high];
	for(int j=low;j<=high;j++){
		if(A[j]<pivot){
			std::cout<<"\n Swap "<<A[i]<<" <-->"<<A[j];
			int temp = A[i];
			A[i]=A[j];
			A[j]=temp;
			i++;
		}
	}
	//Final Element Swap
	std::cout<<"\n Swap "<<A[i]<<" <-->"<<A[high];
	int temp = A[i];
	A[i]=A[high];
	A[high]=temp;
	
	std::cout<<"\n Returning i - "<<i;
        return i;
}
void QuickSort(int A[], int low, int high) {
	std::cout<<"\n Quick Sort Low: "<<low<<" High: "<<high;
	if(low < high) {
		int pi = partition(A,low,high);
		QuickSort(A,low,pi-1);
		QuickSort(A,pi+1,high);
	}
}

void printArray(int A[], int n){
	std::cout<<"\n Array : ";
	for(int i=0;i<n;i++) {
		std::cout<<"\t"<<A[i];
	}
	std::cout<<"\n";
}

int main() {
	int A[] = {4,8,9,6,5,2,1,7,3,10,14,11,90,400,900,123};
	printArray(A,16);
	QuickSort(A,0,15);
	printArray(A,16);
	return 0;
}
