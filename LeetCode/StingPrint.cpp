#include<iostream>
#include<string>
using namespace std;

void printSpace(int num) {
	while(num>0) {
		cout<<" ";
		num--;
	}
}

int main() {
	string input="SHRIKANT";
	int rows =4;
	int len = input.length();
	int spaceLength = rows-2;
	int itr = spaceLength;
	int rowItr = rows;
	for(int i=0; i<rows;i++) {
		int index = i;
		while(index<=len) {
			cout<<input[index];
			printSpace(itr);
			index=index+itr+rowItr;
		}
		cout<<"\n";
		rowItr--;
		itr--;
	}
	return 0;
}
			
		


