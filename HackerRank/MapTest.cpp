#include<iostream>
#include<map>
int main() {

	std::map<int,int> mapList;
	mapList[0]=100;
	mapList[1]=100;
	mapList[5]=100;

	if(mapList[4]) {
		std::cout<<"\n Result :"<<mapList[4];
	}

	return 0;
}
