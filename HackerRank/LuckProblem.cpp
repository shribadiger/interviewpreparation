#include<bits/stdc++.h>
using namespace std;

void customSort(std::vector<std::vector<int>>& Arr, int n){
	for(int i=0;i<n-1;i++){
		int min = i;
		for(int j=i+1;j<n;j++) {
			if(Arr[min][0]>Arr[j][0] && Arr[min][1]&Arr[j][1]){
				min=j;
			
			}
		}
			int value = Arr[min][0];
			int k=Arr[min][1];
			Arr[min][0]=Arr[i][0];
			Arr[min][1]=Arr[i][1];
			Arr[i][0]=value;
			Arr[i][1]=k;
		}
}
int main() {
	//Reading the n and k
	int n = 0;
	int k = 0;
	cin>>n;
	cin>>k;

	int totalLuck= 0;

	std::vector<std::vector<int>> data(n);
	for(int i=0;i<n;i++){
		data[i].resize(2);
		cin>>data[i][0];
		cin>>data[i][1];
		totalLuck+=data[i][0];
	}

	customSort(data,n);

	totalLuck=totalLuck-data[0][0]*2;

	for(int i=0;i<n;i++){
		std::cout<<"\t"<<data[i][0]<<"\t"<<data[i][1]<<endl;
	}

	cout<<"\n Result : "<<totalLuck;
	
	return 0;
}
