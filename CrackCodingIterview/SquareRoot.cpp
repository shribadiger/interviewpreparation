#include<iostream>
using namespace std;


int sqrt_helper(int n, int min, int max) {
	if(max < min) return -1;
	int guess = (min+max)/2;

	if(guess*guess == n) {
		return guess;
	} else if(guess*guess < n){
		return sqrt_helper(n, guess+1, max);
	} else {
		return sqrt_helper(n,min,guess -1);
	}
}
int sqrt(int n) {
	return sqrt_helper(n,1,n);
}

int main() {
	int n;
	cin>>n;
	std::cout<<"\n Result: "<<sqrt(n)<<"\n";

	return 0;
}
