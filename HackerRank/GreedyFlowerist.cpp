#include<iostream>
#include<algorithm>
#include<vector>

int main(){
    int numOfFlowers;
    std::cin>>numOfFlowers;
    int numOfCustomers;
    std::cin>>numOfCustomers;
    std::vector<int> priceList(numOfFlowers,0);
    long totalPrice = 0;
    for(int i=0;i<numOfFlowers;i++){
        std::cin>>priceList[i];
        totalPrice+=priceList[i];
    }
    //Sort Reverse Order
    std::sort(priceList.begin(),priceList.end(),std::greater<int>());
    long minTotalPrice = 0;
    if(numOfCustomers == numOfFlowers || numOfFlowers <numOfCustomers){
        std::cout<<totalPrice;
    } else {
        int custGroups = numOfFlowers/numOfCustomers;
        std::cout<<"\n CustGroup :"<<custGroups;
        for(int i=0,j=0;i<custGroups;i++){
            int loopCount = 0;
            
            while(j<numOfFlowers && loopCount<numOfCustomers){
                std::cout<<"\nj:"<<j<<" i:"<<i<<" loopCount:"<<loopCount<<"\n";
                minTotalPrice +=(i+1)*priceList[j];
                j++;
                loopCount++;
            }
            std::cout<<"\n j:"<<j<<" i:"<<i<<"\n";
        }
        std::cout<<minTotalPrice;
    }
    
    return 0;
}
