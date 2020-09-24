#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main() {
        std::string input;
	cin>>input;
	int length = input.length();
	int count = 0;
	std::set<int> result;
	for(int i=2;i<=length;i++){
		for(int j=0;j<=length-i;j++) {
			int itr=j;
			cout<<"\nItr: "<<itr;
			cout<<"\nLen: "<<(i+j);
                       while(itr<(i+j)){
			       result.insert((int)input[itr]);
			       itr++;
		       }
		       std::cout<<"\n"<<"i: "<<i<<" Result Size: "<<result.size();
		       if(i%2 == 1 && result.size() <= 2){
			       count++;
		       }
		       else if(i%2 ==0 && result.size() ==1){
			       count++;
		       }
		       result.clear();
		}
	}


	cout<<"\n Final Result : "<<count+length;

	return 0;
}
