#include<iostream>
#include<algorithm>

using namespace std;

struct item{
   int num;
   float profit;
   float weight;
   float remaining;	
   float ratio;	
};

bool cmp(struct item i,struct item j) { 
     
        return (i.ratio > j.ratio);

}

int main(){
  int n;
  float value=0.0,weight;
  
  cout<<"\nEnter the number of elements in an array=";
  cin>>n;
  
  struct item arr[n];
  
  cout<<"\nEnter the weight and profit of each element:-\n";
  for(int i=0;i<n;i++){
     cin>>arr[i].weight;
     cin>>arr[i].profit;
     arr[i].ratio=arr[i].profit/arr[i].weight;
     arr[i].remaining=arr[i].weight;
     arr[i].num=i+1;
  }
  
  sort(arr,arr+n,cmp);
  
 /* cout<<"\nArray is as follows:-\n";
  for(int i=0;i<n;i++){
  	 
     cout<<arr[i].weight<<" ";
     cout<<arr[i].profit<<" ";
     cout<<arr[i].ratio;
     cout<<endl;
  }*/

  cout<<"\nEnter the weight=";
  cin>>weight;
  
  int i=0;
  while(weight>0 && i<n){
       if(weight<arr[i].weight){
           arr[i].remaining=arr[i].weight-weight;
           weight=0; 
           i++;
       }
       else{
           arr[i].remaining=0;  
           weight=weight-arr[i].weight;          
           i++;
       }
  }

  cout<<"\nItems used:-\n\n";
  for(i=0;i<n;i++){

      if(arr[i].remaining<arr[i].weight){
            value+=arr[i].ratio*((float)(arr[i].weight-arr[i].remaining));
            cout<<"Item="<<arr[i].num<<"  Weight="<<arr[i].weight-arr[i].remaining<<endl;
      }	
  }
  cout<<"\nMaximum profit="<<value; 
	
}
