#include<iostream>
#include<string.h>
using namespace std;

int main() {
	int n = 10;
	int list[]={10,10,10,30,10,20,20,10,40,50};

	int *result = new int[101];
	memset(result,0,sizeof(int)*101);

	for(int i=0;i<10;i++){
		result[list[i]]++;
	}

	for(int i=0;i<51;i++) {
		if(result[i] != 0)
		std::cout<<"\t"<<result[i];
	}

	return 0;
}
