/*
 * checking the powe of 2 numbers
 */
#include<bits/stdc++.h>
using namespace std;
int powerOf2(int n) {
	if(n<1) {
		return 0;
	}
	else if(n ==1) {
		return 1;
	}
	else {
		int prev = powerOf2(n/2);
		int curr = prev*2;
		std::cout<<"\n"<<curr;
		return curr;
	}
}

int main() {
	int n;
	std::cin>>n;
	std::cout<<"\n Power of 2 : "<<powerOf2(n)<<"\n";
	return 0;
}
