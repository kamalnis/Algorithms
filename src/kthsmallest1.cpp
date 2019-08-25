#include<iostream>

using namespace std;

int minimum(int a, int b) 
{
     if(a<b)
        return a;
     else
        return b;
}



int kthElement(int *arr1,int *arr2,int m,int n,int k){


    int i=minimum(k/2,m);

    int j=minimum(k/2,n);
    
    if(m==0 && n>0)
        return arr2[k-1];

    else if(m>0 && n==0)
        return arr1[k-1];


    if(k==1)
        return minimum(arr1[0],arr2[0]);
   
    if(arr1[i-1]>arr2[j-1])
        return kthElement(arr1,arr2+j,i,n-j,k-j);

    else
        return kthElement(arr1+i,arr2,m-i,j,k-i);
 
}


int main(){

    int m,n,k;
    cout<<"Enter length of first array=";
    cin>>m;
  
    int arr1[m]; 
    cout<<"\nEnter elements in sorted order:-"<<endl;
    for(int i=0;i<m;i++)
        cin>>arr1[i];


    cout<<"\nEnter length of second array=";
    cin>>n;

    int arr2[n]; 
    cout<<"\nEnter elements in sorted order:-"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr2[i];

    for(int i=0;i<4;i++){
         cout<<"\nEnter "<<i+1<<"kth value=";
         cin>>k;
         cout<<"\n"<<kthElement(arr1,arr2,m,n,k)<<endl;
    }
    return 0;
}
