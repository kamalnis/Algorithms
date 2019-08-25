#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int *arr1,int *arr2){

    return *(arr1+2)>*(arr2+2);   
}

int main(){
  int n;
  cout<<"\nEnter the number of friends=";
  cin>>n;
  int arr[n][2],arr2[n];
  cout<<"\nEnter the credit and debt of each friend:-\n";
  for(int i=0;i<n;i++){
    cin>>arr[i][0];
    cin>>arr[i][1];
    arr2[i]=arr[i][0]-arr[i][1];
  }
  sort(arr2,arr2+n);
  int j=n-1;
  for(int i=0;i<j;){
     if(arr2[i]==0)
         i++;  
     else if(arr2[j]==0)
         j--;
     else  if(arr2[i]>arr2[j]){
        if(arr2[i] > abs(arr2[j])){
            arr2[i]+=arr2[j];   
            cout<<"\nFriend "<<i<<" has given money "<<abs(arr2[j])<<" to "<<j;
            arr2[j]=0;
            j--; 
        }
        else{ 
           arr2[j]+=arr2[i];
           cout<<"\nFriend "<<i<<" has given money "<<abs(arr2[i])<<" to "<<j;
           i++;
        }
     }

  }  
}
