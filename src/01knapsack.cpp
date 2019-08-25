#include<iostream>
#include<vector>
using namespace std;

int knapsack(int W,vector<vector<int> > &items,int n){
    vector<vector<int> > table(n+1,vector<int> (W+1, 0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j<items[i-1][0])
                table[i][j]=table[i-1][j];
            else {
                table[i][j]=max(table[i-1][j-items[i-1][0]]+items[i-1][1],table[i-1][j]);
            }
        }
    }
    cout<<"\nTotal Weight="<<W<<"  Total Profit="<<table[n][W];

    return 0;
}

int main(){
   int n,W; 
   cout<<"Enter the number of items and knapsack weight=";
   cin>>n;
   cin>>W;
   vector<vector<int> > items(n,vector<int> (2, 0));
   cout<<"\nEnter the value as weight and value pair:\n";
   for(int i=0;i<n;i++){
      cin>>items[i][0];
      cin>>items[i][1];
   }  
   knapsack(W,items,n);
}