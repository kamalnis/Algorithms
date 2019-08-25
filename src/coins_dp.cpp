#include<cstdio>
#include<iostream>
#include<climits>
 
using namespace std;

int count_coin( int S[], int m, int n )
{
    int i, j, x, y;

    int save[n+1][m];
    
    for (i=0; i<m; i++)
        save[0][i] = 1;
   
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            
            if(i-S[j] >= 0)
                x=save[i - S[j]][j];
            else
                x=0;
 
            
            if(j >= 1)
                y=save[i][j-1];

            else
                y=0;
 
            
            save[i][j] = x + y;
        }
    }
    return save[n][m-1];
}

int min_coin(int coins[], int m, int n)
{
    int save[n+1];
 
    save[0] = 0;
 
    for (int i=1; i<=n; i++)
        save[i] = INT_MAX;
 
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int res = save[i-coins[j]];
              if (res != INT_MAX && res + 1 < save[i])
                  save[i] = res + 1;
          }
    }
    return save[n];
}
 
int main()
{
    int n,m; 
    cout<<"\nEnter the number of demonitions=";
    cin>>m;
    int coins[m];

    cout<<"\nEnter the demonitions:-\n";
    for(int i=0;i<m;i++){
       cin>>coins[i];
    }
    cout<<"\nEnter the sum of money="; 
    cin>>n;
    cout<<"\nNumber of ways="<<count_coin(coins, m, n);
    cout<<"\nMinimum number of coins required=";
    if(INT_MAX==min_coin(coins,m,n))
         cout<<" No way to make change";
    else
        cout<<min_coin(coins,m,n);  
    return 0;
}