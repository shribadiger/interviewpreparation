#include<iostream>
#include<vector>
#include<algorithm>
int main() {
	int n, k ;
	std::cin>>n>>k;
	std::vector<long> arr(n,0);
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];
	}

	std::sort(arr.begin(),arr.end());
	int counter = 0;
	for(int i=0; i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(abs(arr[j]-arr[i]) == k){
				counter++;
				break;
			}
		}
	}
	std::cout<<counter;
	return 0;
}

