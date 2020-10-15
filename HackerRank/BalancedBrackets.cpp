#include<iostream>
#include<vector>
using namespace std;


bool balancedBraces(string input) {
    int len = input.length();
    int top=-1;
    int i=0;
    vector<char> stack(len,0);
    for(i=0; i<len;i++) {
        if(input[i] == '{' || input[i] == '(' || input[i]=='[') {
            top++;
            stack[top]=input[i];   
	    std::cout<<"\n Insert: "<<input[i]; 
            
        } else {
	    cout<< "\n input["<<i<<"] :"<<input[i] <<"   stack["<<top<<"] :"<<stack[top];
            if(input[i] == '}' && stack[top] == '{') {
                stack[top]=0;
                top--;
            }
            else if(input[i] == ')' && stack[top] == '(') {
                stack[top]=0;
                top--;
            }
            else if(input[i] == ']' && stack[top] == '[') {
                stack[top]=0;
                top--;
            }
            else {
                return false;
            }
         }
    }
    if(top == -1 && i == len) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    int numOfTests = 0;
    cin>>numOfTests;
    while(numOfTests > 0) {
        string input;
        cin>>input;
        if(balancedBraces(input)) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
        numOfTests--;
    }
    
    return 0;
}
