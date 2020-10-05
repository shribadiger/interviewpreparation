#include<iostream>
using namespace std;

int power(int a, int b) {

	//break condition
	if(b == 0) {
		return 1;
	}
	else {
		//recursive step
		return a*power(a,b-1);
	}
}

int main() {
	int a,b;
	cin>>a>>b;
	cout<<a<<" power "<<b<<" : "<<power(a,b)<<"\n";
	return 0;
}
