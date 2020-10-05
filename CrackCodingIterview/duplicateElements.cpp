#include<iostream>
using namespace std;

int main() {
	int A[]={13,27,35,40,49,55,59};
	int B[]={17,35,39,40,55,58,59};

	int indexOfB = 0;
        for(int i=0;i<7;i++) {
		while(indexOfB<7){
		if(A[i] == B[indexOfB]) {
			std::cout<<"\t"<<A[i];
			break;
		} else if(B[indexOfB]>A[i]){
			break;
		} else {
			indexOfB++;
		}
		}
	}
	std::cout<<"\n";
	return 0;
}	
