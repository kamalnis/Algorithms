#include<iostream>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;

int main(){

  char str[100],pat[50];

  cout<<"\nEnter the string=";
  cin>>str;
  cout<<"\nEnter the pattern to match=";
  cin>>pat;
  int n=strlen(str);
  int m=strlen(pat);

  int arr[n-m+1];
  int pat_num=0,num=0,k=1;

  for(int i=0;i<m;i++){
     pat_num=(pat_num*256+pat[i])%3313;
     num=(num*256+str[i])%3313;
     //cout<<pat_num<<"  "<<num<<" ";
  }
  for(int i=1;i<m;i++)
       k=(k*256)%3313;

  //cout<<"  k= "<<k<<" ";
  arr[0]=num; 
  for(int i=1;i<=n-m;i++){
      arr[i]=((arr[i-1]-str[i-1]*k)*256)%3313;
      arr[i]=(arr[i]+str[m+i-1]+3313)%3313;
     // cout<<arr[i]<<endl;
  }

  for(int i=0;i<n-m;i++){
     if(arr[i] == pat_num){
         int flag=1;
         for(int j=0;j<m;j++){
             if(str[i+j]!=pat[j]){
                   flag=0;
                   break;
             }         
         } 
         if(flag==1){
             cout<<"\nPattern matches at= "<<i;
         }
     }
  }

} 