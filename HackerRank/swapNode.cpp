/*
 * This is trying to solve the swap node problem from hacker rank
 */

//Input 2D array
#include<iostream>

class Node {
	public:
		Node* left;
		Node* right;
		int val;
		Node(int input):val(input),left(nullptr),right(nullptr) {}
};

int main() {
	int arr[11][2]= {
		{2,3},
		{4,-1},
		{5,-1},
		{6,-1},
		{7,8},
		{-1,9},
		{-1,-1},
		{10,11},
		{-1,-1},
		{-1,-1},
		{-1,-1}
	};
	int k1=2, k2=4; // Swapping the child elements
	/*for(int i=0;i<11;i++){
		std::cout<<"\t"<<arr[i][0]<<" "<<arr[i][1]<<"\n";
	} */

	int root = 1;
	class RootNode = new Node(root);
	for(int i=0;i<11;) {

	}
	return 0;
}
