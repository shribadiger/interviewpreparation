#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n = 0;
    int days = 0;
    cin>>n>>days;
    std::vector<int> exp(n,0);
    int totalCount = 0;
    for(int i=0;i<n;i++){
        cin>>exp[i];
        if(i<days){
            totalCount = totalCount+exp[i];
        }
    }
    std::cout<<"\n Total Count : "<<totalCount<<"\n";

    float meanValue = (float)totalCount /days;
    int mean = (int)ceil(meanValue);
    std::cout<<"\n Mean Value : "<<mean<<endl;
    int notifyCount = 0;
    int prevValue = 0;
    int preIndex = -1;
    int nextValue = 0;
    for(int j=days;j<n;j++){
        if(exp[j]>= 2*mean){
            notifyCount++;
        }
        preIndex++;
        prevValue = exp[preIndex];
        nextValue = exp[j];
        int value = (totalCount-prevValue+nextValue)/days;
        mean = (int)ceil(value);
    }
    std::cout<<notifyCount<<"\n";
    return 0;
}

