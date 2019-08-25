#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int knapsack(int w,int *value,int *weight,int n){
   int save[n+1][w+1];  
   memset(save,0,sizeof(save));
   for(int i=0;i<=n;i++)
        save[i][0]=0;

   for(int i=0;i<=w;i++)
        save[0][i]=0;

   for(int i=1;i<=n;i++){
       for(int j=1;j<=w;j++){
             if(weight[i-1]<=j){
                 save[i][j]=max(value[i-1]+save[i-1][j-weight[i-1]],save[i-1][j]);
             }
             else
                 save[i][j]=save[i-1][j];

       }
   }
  cout<<"\nSave array:-\n\n";
  for(int i=0;i<=n;i++){
       for(int j=0;j<=w;j++){
         cout<<save[i][j]<<" ";
       }
       cout<<endl; 
   }
 
   int profit=0,wt=0;
   for(int i=n;i>0;i--){

              if(save[i][w]!=save[i-1][w]){
                      w=w-weight[i-1];
                      cout<<"Item="<<i-1<<" Value="<<value[i-1]<<" Weight"<<weight[i-1]<<endl;
                      profit+=value[i-1];
                      wt+=weight[i-1]; 
              }             
          
   }
   cout<<"\nTotal Weight="<<wt<<"  Total Profit="<<profit;
   return 0;
}

/*int set_taken(int *arr[n+1],int w,int *value,int *weight){
   int profit=0;
   for(int i=n;i>0;i--){

              if(arr[n][w]!=arr[n-1][w]){
                      w=w-weight[i-1];
                      cout<<"Item="<<i-1<<" Value="<<value[i-1]<<" Weight"<<weight[i-1]<<endl;
                      profit+=value[i-1];
              }             
          
   }

}*/


int main(){
  
  int w,n;
  
  
  cout<<"\nEnter the number of elements in an array=";
  cin>>n;

  int value[n],weight[n];
  //int arr[n][n];
  
  cout<<"\nEnter the weight and profit of each element:-\n";
  for(int i=0;i<n;i++){
     cin>>weight[i];
     cin>>value[i];
  }
  cout<<"\nEnter the size of the knapsack=";
  cin>>w;
  knapsack(w,value,weight,n);
  //set_taken(arr,w,value,weight,n);
  //cout<<"\nMaximum value="<<arr[n][w];
	
}
