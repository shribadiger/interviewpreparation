#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {

	//declare vector
	vector<int> Array;

	Array.reserve(2); // reserving size 2

	assert(Array.capacity()==2);

	Array[0]=1;
	Array[1]=2;

	for(vector<int>::iterator itr = Array.begin(); itr != Array.end(); itr++) {
		cout<<"\n "<<*itr;
	}

	cout<<"\n Value @ index 0 :"<<Array[0];


	Array.reserve(10);

	assert(Array.capacity() == 10);

	Array[2]=1;
	Array[3]=2;
	Array[4]=1;
	Array[5]=2;
	Array[6]=1;
	Array[7]=2;
	Array[8]=1;
	Array[9]=2;
	for(vector<int>::iterator itr = Array.begin(); itr != Array.end(); itr++) {
		cout<<"\n "<<*itr;
	}

	return 0;

}
