#include<iostream>

int main() {

	int A[]={1,2,3,4,5,6,7,9};
	std::cout<<"\n Before Reverse:";
	for(int i=0;i<8;i++) {
		std::cout<<"\t"<<A[i];
	}
        int n=7;
	for(int j=0;j<(8/2);j++) {
		int temp = A[n];
		A[n]=A[j];
		A[j]=temp;
		n--;
	}
	std::cout<<"\n After Reverse:";
	for(int i=0;i<8;i++) {
		std::cout<<"\t"<<A[i];
	}
	std::cout<<"\n";
	return 0;
}
