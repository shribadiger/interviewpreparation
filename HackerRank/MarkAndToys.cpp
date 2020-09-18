#include<iostream>
#include<vector>
using namespace std;
long long result[100000];
void merge(std::vector<long long>& list,int begin, int mid, int end){

	int itr = mid+1;
	int i = begin;
	int j=0;
	while(i<=mid && itr<=end){
		if(list[i]>list[itr]){
			result[j++]=list[itr];
			itr++;
			continue;
		}
		result[j++]=list[i];
		i++;
	}
	while(i<=mid){
		result[j++]=list[i];
		i++;
	}
	while(itr<=end){
		result[j++]=list[itr];
		itr++;
	}
	j=0;
	for(i=begin;i<=end;i++,j++){
		list[i]=result[j];
	}
}
void mergeSort(std::vector<long long>& list, int begin, int end){
	int mid = (begin+end)/2;
	if(begin != end){
		mergeSort(list,begin,mid);
		mergeSort(list,mid+1, end);
	}
	merge(list,begin,mid,end);
}

int main() {
	int n;
	long long sum;
	cin>>n>>sum;
        std::vector<long long> list(n,0);
	for(int i=0;i<n;i++){
		cin>>list[i];
	}
	mergeSort(list,0,n-1);
	std::cout<<"\n Result: ";
	for(int i=0;i<n;i++) {
		std::cout<<"\t"<<list[i];
	}
	int count = 0;
	int i = 0;
	int refCount=0;
	while((count + list[i])<=sum && i<n){
		count=count+list[i];
		refCount++;
		i++;
	}
	std::cout<<refCount<<"\n";
	return 0;
}
