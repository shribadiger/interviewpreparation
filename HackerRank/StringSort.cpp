#include<iostream>
#include<string>
using namespace std;

int main() 
{
	std::string a1 = "aaaddc";
	std::string a2 = "aabbc";
	if(a1>a2) {
		std::cout<<"\n A1: "<<a1<<" > A2: "<<a2;
	}
	else if(a1<a2) {
		std::cout<<"\n A1 "<<a1<<" < A2: "<<a2;
	}
	else {
		std::cout<<"\n A1 "<<a1<<" = A2: "<<a2;
	}
	return 0;
}
