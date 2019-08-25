#include<iostream>
#include<vector>

using namespace std;

int coinChange(vector<int> &coins,int n,int val){
    vector<vector<int> > table(n+1,vector<int> (val+1,0));

    for(int i=1;i<=n;i++){
        table[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<= val;j++){
            if(j>=coins[i-1]){
                table[i][j]=table[i-1][j]+table[i][j-coins[i-1]];
            }
            else{
                table[i][j]=table[i-1][j];
            }
        }
    }
    return table[n][val];
}
int main(){
    int n,val;
    cout<<"Enter the number of coins available=";
    cin>>n;
    vector<int> coins(n);
    cout<<"Enter all the demonition=";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<"Enter the value for change=";
    cin>>val;

    cout<<"Number of possible ways="<<coinChange(coins,n,val);
}