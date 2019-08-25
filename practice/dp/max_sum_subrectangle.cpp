#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define loop(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define loopd(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define bit(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 111


int rec[1000][1000]={{1, 2, -1, -4, -20},
                     {-8, -3, 4, 2, 1},
                     {3, 8, 10, 1, 3},
                     {-4, -1, 1, 7, -6}
                   };

int kadane(vector<int> &arr,int &start,int &end,int n){

     int sum=0,max_sum=-1e9;
     end=-1;
     int l_start=0;
     for(int i=0;i<n;i++){
         sum+=arr[i];
         if(sum<0){
            sum=0;
            l_start=i+1;

         }
         else if(sum>max_sum){
           max_sum=sum;
           start=l_start;
           end=i;
         }
     }
     if(end!=-1){
        return max_sum;
     }
     max_sum=arr[0];
     start=end=0;
     for(int i=0;i<n;i++){
          if(arr[i]>max_sum){
            max_sum=arr[i];
            start=end=i;
          }

     }
     return max_sum;

}

int max_sum_rectangle(int &max_l,int &max_r,int &max_u,int &max_d,int row,int col){
    max_l=0,max_r=0,max_u=0,max_d=0;
    int max_sum=-1e9,cur_sum=0;

    for(int l=0;l<col;l++){
       vector<int> save; //for saving status when traversing from left to right
       for(int i=0;i<row;i++)
          save.pb(0); //initializing with the first column

       for(int r=l;r<col;r++){
            for(int i=0;i<row;i++)
               save[i]+=rec[i][r];

            int start,end;
            cur_sum=kadane(save,start,end,row);
            if(cur_sum>max_sum){
              max_l=l,max_r=r,max_u=start,max_d=end;
              max_sum=cur_sum;

            }

       }


    }
    return max_sum;

}

int main()
{
  /*rec[4][] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                     };*/

    int max_l,max_r,max_u,max_d;

    cout<<max_sum_rectangle(max_l,max_r,max_u,max_d,4,5)<<" l="<<max_l<<" r="<<max_r<<" u="<<max_u
        <<" d="<<max_d<<endl;

    return 0;
}
