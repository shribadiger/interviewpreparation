#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	std::string s1,s2;
	cin>>s1;
	cin>>s2;
	std::cout<<" S1 : "<<s1<<endl;
	std::cout<<" S2 : "<<s2<<endl;
        
	int len1 = s1.size();
	std::cout<<"\n Length of S1 : "<<len1;


	int len2 = s2.size();
	std::cout<<"\n Length of S2 : "<<len2;

	std::map<char, signed int> charMapper;
        int i = 0;
	int counter = 0;
	while(len1>0){
		charMapper[s1[i]]++;
		len1--;
		i++;
	}
	i=0;
	bool found = false;
	while(len2>0) {
		if(charMapper[s2[i]] > 0) {
			counter++;
		}
		if(counter == 3){
			found = true;
			break;
		}
		len2--;
		i++;
	}
	if(found) {
		std::cout<<"YES\n";
	}
	else {
		std::cout<<"NO\n";
	}
	/*std::map<char, signed int>::iterator itr = charMapper.begin();
	while(itr!= charMapper.end()){
		std::cout<<"\n"<<itr->first<<"-->"<<itr->second;
		itr++;
	}*/

	return 0;
}


