#include<iostream>
using namespace std;

int main() {
	int m,w,p,n;
	cin>>m>>w>>p>>n;
	
	int midRange = 0;
	if(n%2 == 0) {
		midRange=n/2;
	}
	else {
		midRange=n/2+1;
	}

	int result = 0;
	int loopCount = 1;
	int gain= 0;
	result=m*w;
	while(result<n/2) {
		std::cout<<"\n Result: "<<result;
		if(result>=p) {
		gain = result/p;
		std::cout<<"\n gain : "<<gain;
		result = result%p;
		if(m<w) {
			m=m+gain;
		} else {
			w=w+gain;
		}
		}
		result = result+(m*w);
		loopCount++;
	}
	std::cout<<"\nCount: "<<loopCount+1;
			
	return 0;
}
