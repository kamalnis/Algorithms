#include<iostream>
#include<vector>
#include<utility>
using namespace std;

pair<int,int> findBuySellPrice(vector<int> &sharesPrice){
    int n=sharesPrice.size();
    int buy=sharesPrice[0],sell=INT_MIN; 
    int maxProfit=0;
    for(int i=1;i<n;i++){
        if(maxProfit < sharesPrice[i]-buy){
            maxProfit=sharesPrice[i]-buy;
            sell=sharesPrice[i];
        }
        if(sharesPrice[i] < buy)
            buy=sharesPrice[i];
    }
    pair<int,int> mypair;
    if(maxProfit==0){
        mypair=make_pair(-1,-1);
    }
    else{
        mypair=make_pair(buy,sell);
    }
    return mypair;

}

int main(){
    int n;
    cout<<"Enter the shares value minute by minute = ";
    cin>>n;

    vector<int> sharesPrice(n,0);

    for(int i=0;i<n;i++){
        cin>>sharesPrice[i];
    }
    
    pair<int,int> buySellPrice = findBuySellPrice(sharesPrice);
    if(buySellPrice.first == -1 || buySellPrice.second == -1){
        cout<<"\nNothing bought and sold"<<endl;
    }
    else{
        cout<<"\nBuy = "<<buySellPrice.first<<" Sell = "<<buySellPrice.second<<endl;
    }
}