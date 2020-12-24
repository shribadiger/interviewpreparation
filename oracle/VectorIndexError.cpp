#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> Array;

	//cout<<"\n Vector[0]:"<<Array[0]; //--> Segmentation fault
	try {
		cout<<"\n Vector.at(0) : "<<Array.at(0);
	}
       	catch(...) {
		std::cout<<"\n Generic Execption\n";
	}
	return 0;
}
