#include<iostream>
using namespace std;
int result[100];

void merge(int list[],int begin, int mid, int end);
void mergeSort(int list[], int begin, int end){
	for(int i=begin;i<=end;i++){
		cout<<"\t"<<list[i];
	}
	cout<<"\n";
	int mid = (begin+end)/2;
	if(begin != end){
		mergeSort(list,begin,mid);
		mergeSort(list,mid+1, end);
	}
	merge(list,begin,mid,end);
}

void merge(int list[],int begin, int mid, int end){
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
	std::cout<<"\n Result : ";
	for(i=begin;i<=end;i++){
		std::cout<<"\t"<<list[i];
	}
	std::cout<<"\n";
}
int main() {
	int list[]={9,8,7,6,5,4,3,2,1,0}; 
	int n = 10; //Length of the Array

	mergeSort(list,0,n-1);
	for(int i=0; i<n;i++) {
		cout<<"\t"<<list[i];
	}
	return 0;
}
