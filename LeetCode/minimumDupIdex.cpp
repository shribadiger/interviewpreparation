#include<iostream>
using namespace std;

int main() {
	int A[]={2,1,3,5,3,2};
	
	int first_dup_index = 6;
	
	for(int i=0; i<6;i++) {
		for(int j=i+1;j<6;j++) {
			if(A[i] == A[j]) {
				if(first_dup_index > j) {
					first_dup_index = j;
				}
			}
		}
	}
	if(first_dup_index == 6) 
		first_dup_index = -1;
	cout<<"\n Result: "<<first_dup_index;
	return 0;
}
