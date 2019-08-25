#include<iostream>
#include<climits>
using namespace std;

int sum=0;
int merge(int *arr,int p,int q,int r){
  int n1=q-p+1;
  int n2=r-q;
  
  int arr1[n1+1],arr2[n2+1];

  int l=0,m=0;

  for(int i=0;i<n1;i++)
     arr1[i]=arr[p+i];

  for(int i=0;i<n2;i++)
     arr2[i]=arr[q+i+1];

  arr1[n1]=arr2[n2]=INT_MAX;

  for(int i=p;i<=r;i++){
      if(arr1[l]<=arr2[m])
          arr[i]=arr1[l++];

      else {
          sum=sum+(n1-l);
          arr[i]=arr2[m++];  
      }
  }
  return 0;
}

int mergesort(int *arr,int p,int q){
  
  if(p<q){

    int mid=(q+p)/2;
    mergesort(arr,p,mid);
    mergesort(arr,mid+1,q);
    merge(arr,p,mid,q);
  }
  return 0;

}

int main(){
  int n,t;
  cout<<"\nEnter the number of testcases=";
  cin>>t;
  while(t--){
     cout<<"\nEnter the number of elements in an array=";
     cin>>n;

     int arr[n];
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     mergesort(arr,0,n-1);
     cout<<endl;
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
     cout<<"\nTotal number of swapping needed="<<sum<<"\n\n";
  }
}



