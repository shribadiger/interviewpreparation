#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
    int n = 0;
    cin>>n;
    std::map<int, int> valueMap;
    while(n>0){
        int op = 0;
        int value = 0;
        cin>>op>>value;
        switch(op){
            case 1:
                    valueMap[value]++;
                    break;
            case 2:
                    if(valueMap[value]!=0){
                        valueMap[value]--;
                    }
                    break;
            case 3:
                    if(valueMap[value]!=0){
                        std::cout<<"1\n";
                    } else {
                        std::cout<<"0\n";
                    }
        }
        n--;
    }
    return 0;
}
