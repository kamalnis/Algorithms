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

#define BIT(n) (1<<(n))
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


int arr[100000],n,c;

int fn(int x){
   int prev=arr[0],temp=1;

   loop(i,1,n-1){
       if(arr[i]-prev >= x){
          temp++;
          if(temp==c)
              return 1;
          prev=arr[i];

       }

   }
   return 0;


}

int binary_search(){
    int lo,hi,mid;
    lo=0;hi=arr[n-1];

    while(lo<hi){
        mid=(lo+hi)/2;
        if(fn(mid)==1){
            lo=mid+1;

        }
        else
            hi=mid;

    }
    cout<<lo-1<<endl;
    return 0;
}

int main(){
   int t;
   cin>>t;
   while(t--){
      cin>>n>>c;
      rep(i,n){
        cin>>arr[i];
      }
      sort(arr,arr+n);
      binary_search();


   }

   return 0;
}
