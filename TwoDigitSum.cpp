#include<iostream>
using namespace std;

int main()
{
	int val=123;

	while( (val/10) != 0) {
		int num=val % 10;
		if(num == 0){
			std::cout<<"\t"<<num;
			val=val/10;
		}
		else {
			std::cout<<"\t"<<num;
			val=val/10;
		}
	}
	std::cout<<"\t"<<val;
}
