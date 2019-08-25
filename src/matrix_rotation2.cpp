#include<iostream>
typedef long long ll;
using namespace std;
 
int main(){
    ll m,n,r;
    cin>>m>>n>>r;
    ll matrix[m][n];

    for(ll i=0;i<m;i++)
       for(ll j=0;j<n;j++)
           cin>>matrix[i][j];  
    if(min(m,n)==m)
      //while(r--)
       for(ll i=0;i<m/2;i++){
          ll x=r%((n-2*i)*2+(m-2*i)*2-4); 
          while(x--){
          ll temp=matrix[i][i];
          for(ll j=i;j<n-i-1;j++)
               matrix[i][j]=matrix[i][j+1];

          for(ll j=i;j<m-i-1;j++)
               matrix[j][n-i-1]=matrix[j+1][n-i-1]; 

          for(ll j=n-i-1;j>i;j--)
              matrix[m-i-1][j]=matrix[m-i-1][j-1]; 

          for(ll j=m-i-1;j>i+1;j--)
             matrix[j][i]=matrix[j-1][i];

          matrix[i+1][i]=temp; 
         }}

     else
       //while(r--)
         for(ll i=0;i<n/2;i++){
          ll x=r%((n-2*i)*2+(m-2*i)*2-4); 
          while(x--){
          ll temp=matrix[i][i];
          for(ll j=i;j<n-i-1;j++)
               matrix[i][j]=matrix[i][j+1];

          for(ll j=i;j<m-i-1;j++)
               matrix[j][n-i-1]=matrix[j+1][n-i-1]; 

          for(ll j=n-i-1;j>i;j--)
              matrix[m-i-1][j]=matrix[m-i-1][j-1]; 

          for(ll j=m-i-1;j>i+1;j--)
             matrix[j][i]=matrix[j-1][i];

          matrix[i+1][i]=temp; 
        }}  


    for(ll i=0;i<m;i++){
         for(ll j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";

         cout<<endl; 

    }          
     
}