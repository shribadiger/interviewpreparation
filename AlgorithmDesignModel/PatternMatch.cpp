/*
 * A simple Patten Match algorithm
 * */
#include<iostream>
#include<cstring>
using namespace std;

int main() {
	std::string text = "abzyababxyza";
	std::string pattern = "xyz";

	int n = text.size();
	int m = pattern.size();

	std::cout<<"\n Length Of Text : "<<n<<"\n Length of Pattern : "<<m<<"\n";

	//now compare the string with difference of length
	for(int i=0;i<(n-m);i++) {
		int j=0;
		while(j<m && text[i+j] == pattern[j])
			j++;
		if(j == m) // indicate the match
		{
			std::cout<<"\n Match Found";
			return i;
		}
	}
	std::cout<<"\n No Match in Text\n";

	return 0;
}
