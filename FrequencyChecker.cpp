#include<iostream>
#include<map>
using namespace std;

int main() {
          int val = 0;
	  cin>>val;
	  std::map<int,int> mapper;
	  while(val>0){
		int a = 0;
		int b = 0;
		cin>>b;
		int ele = mapper[b];
		cout<<"\nElement : "<<ele;
		val--;
	  }

	  return 0;
}

