#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main() {
	int A[]={2,1,3,5,3,2};

	set<int> result;

	std::pair<set<int>::iterator, bool> ret;

	int firstDuplicateIndex = 6;

	for(int i=0;i<6;i++) {
		ret=result.insert(A[i]);
		if(ret.second == false) {
			firstDuplicateIndex = min(firstDuplicateIndex,i);
		}
	}

	cout<<"\n Result : "<<firstDuplicateIndex;

	return 0;
}
