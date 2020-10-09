#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int numOfTestCases = 0;
    cin>>numOfTestCases;
    string s1,s2;
    while(numOfTestCases != 0 ) {
        cin>>s1>>s2; //read two strings
        //s1: is input string
        //s2: is matching string
        int itr=0;
        //first condition last char should match 
        if(s1[s1.length()-1] != s2[s2.length()-1]){
            std::cout<<"NO\n";
            numOfTestCases--;
            continue;
        }
       
        for(int i=0;i<s1.length();i++) {
            if(toupper(s1[i]) == s2[itr]){
                itr++;
            }
            if(itr == s2.length()) {
                std::cout<<"YES\n";
                break;
            }
        }
        if(itr != s2.length()) {
            std::cout<<"NO\n";
        }
        
        numOfTestCases--;
    }
    return 0;
}
