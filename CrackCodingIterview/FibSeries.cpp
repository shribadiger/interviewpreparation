#include<iostream>
using namespace std;

int fib(int n) {
	if(n<=1) return 1;
	return n*fib(n-1);
}

int main() {
	int n=5;
	std::cout<<"\nResult: "<<fib(n)<<endl;
	return 0;
}
