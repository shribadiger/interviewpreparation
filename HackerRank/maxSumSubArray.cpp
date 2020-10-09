#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int size;
	cin>>size;
	vector<int> data(0,size);
	for(int i=0;i<size;i++) {
		int input;
		cin>>input;
		data.push_back(input);
	}

	int inc=data[0]; //indicates the include of element to subarray
	int exc=0;  // execute -> element is not ready to be part of sub array
	
	for(int i=1; i<size;i++) {
		//Now we need to find new include and new exclude element
		int new_inc = exc+data[i];
		int new_exc = std::max(inc,exc); // from old include and excute max vlaue we need to add
		inc = new_inc;
		exc =  new_exc;
	}
	std::cout<<"\n Final result : "<<std::max(inc,exc)<<"\n";
	return 0;
}
		
