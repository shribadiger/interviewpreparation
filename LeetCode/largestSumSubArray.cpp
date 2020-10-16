#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {

	vector<int> list={-2,-3,4,-1,-2,1,5,-3};

	cout<<"\n Size of input: "<<list.size();

	int max_end_here = 0;
	int max_so_far = INT_MIN;

	for(int i=0;i<list.size(); i++) {
		max_end_here = max_end_here+list[i];
		if(max_end_here < list[i]){
			max_end_here = list[i];
		} 

		if(max_so_far < max_end_here) {
			max_so_far = max_end_here;
		}
	}

	cout<<"\n Result: "<<max_so_far;
	return 0;
}
