/*
 * computing the mod of two numbers
 */
#include<iostream>
using namespace std;

int main() {
	int a,b;
	std::cin>>a>>b;

	if(b<=0) {
		return -1;
	}

	int div = a/b;
	std::cout<<a<<"%"<<b<<":"<<(a-div*b)<<"\n";
	return 0;
}

