#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin>>n;
	std::vector<long long> list(n,0);

	for(int i=0;i<n;i++) {
		cin>>list[i];
	}

	int swapCount = 0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(list[i]>list[j]){
				swapCount++;
				long long temp = list[i];
				list[i]=list[j];
				list[j]=temp;
			}
		}	
	}

	//print the sorted array
	for(int i=0;i<n;i++){
		cout<<"\t"<<list[i];
	}

	std::cout<<"\n Number Of Swap : "<<swapCount<<"\n";
	return 0;
}
