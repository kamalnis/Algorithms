#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> multiply(vector<int> &a,vector<int> &b){
    vector<int> c(a.size()+b.size()+10,0);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            c[i+j]+=a[i]*b[j];
        }
    }
    for(int i=0;i<c.size();i++){
    //   int num_digit=c[i] > 0 ? (int) log10 ((double) c[i]) + 1 : 1;
       int temp=c[i];
       c[i]=0;
       int count=0;
       while(temp!=0){
           c[i+count]+=temp%10;
           temp/=10;
           count++;
       }
    }
    return c;
}
int main(){
int t;
cin>>t;
while(t--){
   int n;
   cin>>n;
   vector<int> num;  
   num.push_back(1);
   for(int i=2;i<=n;i++){
       vector<int> b;
       int temp=i;
       while(temp!=0){
           b.push_back(temp%10);
           temp/=10;
       }
       num=multiply(num,b);
   }
   long long int sum=0;
   for(int i=0;i<num.size();i++){
       sum+=num[i];
   }
    cout<<sum<<endl;
}    
}