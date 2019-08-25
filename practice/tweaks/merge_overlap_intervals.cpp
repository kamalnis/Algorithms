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


void merged_intervals(vector<pair<int,int> > &interval,int n){
      if(n<=0)
          return;

      stack<pair<int,int> > s;
      sort(interval.begin(),interval.end());
      s.push(interval[0]);

      for(int i=1;i<interval.size();i++){
          pair<int,int> p=s.top();

          if(p.second<interval[i].first)
              s.push(interval[i]);

          else if(p.second<interval[i].second){
               p.second=interval[i].second;
               s.pop();
               s.push(p);
          }
      }
      cout << "\n The Merged Intervals are: ";
      while (!s.empty())
      {
         pair<int,int> t = s.top();
         cout << "[" << t.first << "," << t.second << "] ";
         s.pop();
      }
      return;

}

int main()
{
    //Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    //int n = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int,int> > interval;
    interval.pb(mp(6,8));
    interval.pb(mp(1,9));
    interval.pb(mp(2,4));
    interval.pb(mp(4,7));
    merged_intervals(interval, 4);
    return 0;
}
