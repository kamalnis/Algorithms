#include<iostream>

using namespace std;

int save[100],n;

void print(int *arr){

   for(int i=0;i<n;i++){
        if(save[i]==1)
              cout<<arr[i]<<" ";

   } 

}

void initialize(){
   for(int i=0;i<100;i++){
          save[i]=0;     

   } 
}

int sos(int *arr,int x,int i){

   if(x<0){ 
       return 0;
   }
   if(x==0){
       cout<<"\n";
       print(arr);
       cout<<"\n";
       return 1;
   }
   if(i<0)
      return 0;

   else{
       save[i]=1;
       int a=sos(arr,x-arr[i],i-1);     

       save[i]=0;
       int b=sos(arr,x,i-1);
   }
}

int main(){

   int x;
   cout<<"\nEnter the size of set=";
   cin>>n;
   int *arr=new int[n];
   cout<<"\nEnter the non-negative integer values of the set:-\n";
   for(int i=0;i<n;i++){
          cin>>arr[i];
   }
   cout<<"\nEnter the sum X=";
   cin>>x;
   initialize();
   sos(arr,x,n-1);
   return 0;
}
