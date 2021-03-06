#include<iostream>
#include<vector>
using namespace std;
int swapCount = 0;

void merge(std::vector<long long>& Array, int begin, int mid, int end){
    std::vector<long long> temp;
    int i=begin;
    int j=mid+1;
    while(i<=mid && j<=end){
        if(Array[i]>Array[j]){
            temp.push_back(Array[j]);
            swapCount=swapCount+(mid-i);
            j++;
        }
        else{
            temp.push_back(Array[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(Array[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(Array[j]);
        j++;
    }
    //revert Array to main Array
    for(int i=begin,j=0;i<=end;i++){
        Array[i]=temp[j];
        j++;
    }
}
void mergeSort(std::vector<long long>& Array, int begin, int end)
{
    int mid = (begin+end)/2;
    if(begin<end){
        mergeSort(Array, begin,mid);
        mergeSort(Array, mid+1, end);
        merge(Array,begin,mid,end);
    }
}
int main() {
    int d;
    cin>>d;
    while(d>0){
        int n;
        cin>>n;
        std::vector<long long> Array(n,0);
        for(int i=0;i<n;i++){
            cin>>Array[i];
        }
        mergeSort(Array,0,n-1);
        std::cout<<"\n Result : "<<swapCount;

	std::cout<<"\n Array: ";
	for(int i=0;i<n;i++) {
		std::cout<<"\t"<<Array[i];
	}

        d--;
    }
}
