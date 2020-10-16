#include<iostream>
#include<vector>
using namespace std;

bool isCyclic(vector<int> A) {

	int fastPtr = 1;
	int slowPtr = 0;

	while(true) {
		if(A[fastPtr] == A[slowPtr]) {
			return true;
		}
		fastPtr++;
		if(fastPtr >=A.size() && slowPtr<fastPtr) {
			//reset the fast pointer
			slowPtr++;
			fastPtr=slowPtr;
		}
	}
}

int main() {
	vector<int> A{1,2,6,3,4,5};

	if(isCyclic(A)) {
		cout<<"\nYes";
	}
	else {
		cout<<"\nNo";
	}

	return 0;
}
