#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
   int n;
   cout<<"\nEnter the number of elements in an array=";
   cin>>n;
   cout<<"\nEnter the elements of array:-";

   int arr[n+1]; 
   for(int i=1;i<=n;i++){
     cin>>arr[i];
     arr[i]++;
   } 
 
   cout<<"\nRepeated element is as follows:\n";
   int j=0,k=0; 
   for(int i=1;i<=n;i++){
         if(arr[abs(arr[i])]>=0){
             /* if(abs(arr[i])==0){
                 if(j>0)
                   cout<<"0 ";
                 else
                    j++; 
              }
              else{*/
               arr[abs(arr[i])]=-arr[abs(arr[i])]; 

              //}

         }
         else{
            cout<<abs(arr[i])-1<<" ";
            k++;
         }
   }
   if(k==0)
     cout<<"\nNo elements are repeated";
}