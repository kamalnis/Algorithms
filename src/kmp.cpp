#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){

  char str[100],pat[50];

  cout<<"\nEnter the string=";
  cin>>str;
  cout<<"\nEnter the pattern to match=";
  cin>>pat;
  int arr[strlen(pat)];
  int j=0;
  arr[j]=0;
  for(int i=1;i<strlen(pat);i++){
   
      if(pat[i]==pat[j]){
        arr[i]=j+1;
        j++;  
      }
      else{ 
        while(pat[j]!=pat[i] && j!=0){
          j=arr[j-1];
        }
        if(pat[i]!=pat[j] && j==0){
               arr[i]=j;
              
        }
        else{
              arr[i]=j+1;
              j++; 
        } 
      }
  }
  j=0;  
  for(int i=0;i<strlen(str);i++){
           
      if(str[i]==pat[j]){
         j++;

      }
      else if(j!=0){
         j=arr[j-1];
         if(str[i]==pat[j])
             j++;
      } 
      if(j==strlen(pat)){
          cout<< i-j+1<< " "<<i<<endl; 
          j=0;
      } 

  } 

} 