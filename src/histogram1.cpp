#include<iostream>
#include<climits>
#include<bits/stdc++.h>

using namespace std;

int calculate(int *arr,int n,int length)
{
   int max=INT_MIN,k=0; 
   for(int i=0;i<n;i++){
     /* k=0;
      while(arr[i]>=0){
          k++;
          i++;
      } 
      if(k>max)
         max=k;
      */
      if(arr[i]>=0)
         k=k+1;
      else{
        if(max<k)
           max=k;
   
        k=0;
     }   
   }
   if(max<k)
      max=k;
   cout<<max*length<<endl;
   return max*length;
}

int largest_rectangle(int *histogram, int n,int min){
    int temp[n],temp1[n];
    for(int i=0;i<n;i++)
        temp[i]=histogram[i];
    int area=INT_MIN;
    for(int i=0;i<n;i++){
    	if(temp[i]>=min)
          for(int j=0;j<n;j++){
           temp1[j]=histogram[j]-temp[i];
           cout<<temp[j]<<" "; 
          }
        cout<<endl;
        int k=calculate(temp1,n,temp[i]); 
        if(area<k)
              area=k;      

    }
   return area;
}

int main(){

  int n,min=INT_MAX;
  cout<<"\nNumber of histogram=";
  cin>>n;

  int histogram[n];
  memset(histogram,0,sizeof(histogram));

  for(int i=0;i<n;i++){
    cin>>histogram[i];
    if(min>histogram[i])
       min=histogram[i];
  }
  //cout<<min<<" "<<max<<endl;  
  cout<<"\nLargest rectangle="<<largest_rectangle(histogram,n,min)<<endl;
  return 0;

}
