#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void printArray(std::vector<int> A) {
	for(int i=0;i<A.size();i++) {
		cout<<"\t"<<A[i];
	}
	cout<<"\n";
}
int main() {

	std::set<long> A;
	std::set<long> B;
	std::set<long> C;
	int lenOfA,lenOfB,lenOfC;
	cin>>lenOfA>>lenOfB>>lenOfC;
	for(int i=0;i<lenOfA;i++) {
		int temp;
		cin>>temp;
		A.insert(temp);
	}
	for(int j=0;j<lenOfB;j++) {
		int temp;
		cin>>temp;
		B.insert(temp);
	}
	for(int k=0;k<lenOfC;k++) {
		int temp;
		cin>>temp;
		C.insert(temp);
	}
	int result = 0;

/*	std::set<int>::iterator itrOfA;// = A.cbegin();
	std::set<int>::iterator itrOfB;// = B.cbegin();
	std::set<int>::iterator itrOfC;// = C.cbegin(); */

	auto itrOfA = A.begin();
	while(itrOfA != A.end()){
		auto itrOfB = B.begin();
		while(itrOfB != B.end()){
			if(*itrOfA <= *itrOfB) {
				auto itrOfC = C.begin();
				while(itrOfC != C.end()){
					if(*itrOfB >= *itrOfC){
						result++;
					}
					itrOfC++;
				}
			}
			itrOfB++;
		}
		itrOfA++;
	}
	std::cout<<"\nResult: "<<result;
}
