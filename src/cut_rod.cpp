#include<iostream>
#include<cstdio>
#include<climits>
 
using namespace std;

int rod(int price[], int n)
{
   int value[n+1];
   value[0] = 0;
 
   for (int i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (int j = 0; j < i; j++)
         max_val = max(max_val, price[j] + value[i-j-1]);
       value[i] = max_val;
   }
 
   return value[n];
}
 
int main()
{
    int n;
    cout<<"\nEnter the length of the rod=";
    cin>>n;
    
    int arr[n];

    cout<<"\nEnter the the value of each length from 1 to n:-\n";
    for(int i=0;i<n;i++)
       cin>>arr[i];

    printf("Maximum Profit= %d\n",rod(arr,n));

    return 0;
}