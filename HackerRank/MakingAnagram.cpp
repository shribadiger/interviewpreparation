#include<iostream>
#include<string>
#include<memory.h>
using namespace std;

int calculateAnagram(std::string str1,std::string str2){
    int str1Length = str1.length();
    int str2Length = str2.length();
    //std::cout<<"\n Length 1 :"<<str1Length+1;
    //std::cout<<"\n Length 2 :"<<str2Length+1;
    int **Arr = new int*[str1Length+1];
    for(int i=0;i<str1Length+1;i++){
        Arr[i]=new int[str2Length+1];
        memset(Arr[i],0,sizeof(int)*(str2Length+1));
    }


    //Predefinition
    for(int i=0;i<str1Length+1;i++) {
       for(int j=0;j<str2Length+1;j++) {
	       if(i==0 || j==0) {
		       Arr[i][j]=i+j;
	       }
	       else {
	       if(str1[i] == str2[j]){
		       Arr[i][j]=Arr[i-1][j-1];
	       }
	       else {
		       Arr[i][j]=Arr[i-1][j]+1;
	       } 
	       }
       } 
    }

    for(int i=0;i<str1Length;i++){
	    for(int j=0;j<str2Length;j++) {
		    cout<<Arr[i][j];
	    }
	    std::cout<<"\n";
    }
    return Arr[str1Length][str2Length];

}
int main()
{
    std::string str1;
    std::string str2;
    cin>>str1;
    cin>>str2;
    //std::cout<<"\n String 1: "<<str1;
    //std::cout<<"\n String 2: "<<str2;
    std::cout<<calculateAnagram(str1,str2);
    return 0;
}
