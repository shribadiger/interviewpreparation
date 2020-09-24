#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){
	int ret = a>b?a:b;
	return ret;
}

int main() {
	string s1="";
	string s2="";
	cin>>s1;
	cin>>s2;

	int len1 = s1.length();
	int len2 = s2.length();

	std::cout<<"\n Length1: "<<len1<<" Length2: "<<len2;

        int** result = new int*[len1+1];
        for(int i = 0; i < len1+1; ++i) {
             result[i] = new int[len2+1];
        }
        int prevMatch = len2;
	bool isalreadyMatched = false;
	for(int i=1;i<len1+1;i++){
		for(int j=1;j<len2+1;j++){
			//std::cout<<"\n"<<s1[i-1]<<" == " <<s2[j-1];
			if(s2[i-1]==s1[j-1]){
				result[i][j]=result[i-1][j-1]+1;
			}
			else{
				result[i][j]=max(result[i-1][j],result[i][j-1]);
			}
		}
	}


        for(int i=0;i<len1+1;i++){
		for(int j=0;j<len2+1;j++){
			std::cout<<"\t"<<result[i][j];
		}
		std::cout<<endl;
        }
	return 0;
}


