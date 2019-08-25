#include<iostream>

using namespace std;

int main(){

   int n;
   char temp;
   cout<<"\nEnter the size of the array=";
   cin>>n;
   char *arr=new char[n];
   cout<<"\nEnter the 3 types of character '0' '1' '2' into the array=\n";
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }

    int i=0,j=0,k=n-1;

    while(j<=k){
         if(arr[j]=='0'){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;j++;
          }

         else if(arr[j]=='1')
               j++;

         else{
            temp=arr[k];
            arr[k]=arr[j];
            arr[j]=temp;
            k--;
         }
    }

   cout<<"\nSorted elements is as follows:-\n\n";

     for(int i=0;i<n;i++)
         cout<<arr[i]<<" ";

     cout<<"\n";
     return 0;
}
   
 
 

