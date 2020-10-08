#include<iostream>
#include<set>
#include<algorithm>
#include<map>

using namespace std;


int main() {
        set<long> A;
        set<long> B;
        set<long> C;

        int lenOfA;
        int lenOfB;
        int lenOfC;

        cin>>lenOfA;
        cin>>lenOfB;
        cin>>lenOfC;

        for(int i=0;i<lenOfA;i++) {
                int input;
                cin>>input;
                A.insert(input);
        }
        for(int i=0;i<lenOfB;i++) {
                int input;
                cin>>input;
                B.insert(input);
        }
        for(int i=0;i<lenOfC;i++) {
                int input;
                cin>>input;
                C.insert(input);
        }

	auto itrA=A.begin();
	auto itrB=B.begin();
	auto itrC=C.begin();

	int leftCount = 0;
	int rightCount = 0;
	int result = 0;

	while(itrB != B.end()) {

		while(itrA != A.end() && *itrA<=*itrB) {
			leftCount++;
			itrA++;
		}

		while(itrC != C.end() && *itrB>=*itrC) {
			rightCount++;
			itrC++;
		}
		result = result+leftCount*rightCount;
		itrB++;
	}

	std::cout<<result<<"\n";
	return 0;
}
