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

vector<pair<int,pair<int,int> > >g; //weight , x, y storing the edge
vector<int> pset;
void initSet(int n){
    pset.assign(n,0);
    for(int i=0;i<n;i++)
          pset[i]=i;
}
int findSet(int i){
  return (pset[i]==i)?i:(pset[i]=findSet(pset[i]));
}

bool isSameSet(int i,int j){
  return findSet(i)==findSet(j);
}

void unionSet(int i,int j){
  pset[findSet(i)]=findSet(j);
}

int main(){
   int n,e,s;
   cin>>n>>e;

   for(int i=0;i<e;i++){
       int a,b,c;
       cin>>a>>b>>c;

       //g[i].first=c;
       //g[i].second.first=a-1;    //for matching the indexing
       //g[i].second.second=b-1;   //for matcing the indexing
       g.push_back(make_pair(c,make_pair(a-1,b-1)));
   }
   cin>>s;
   s=s-1;
   initSet(n);
   sort(g.begin(),g.end());
   int cost=0;
   vector<pair<int,int> > res;  //for saving the spanning tree edges

   for(int i=0;i<e;i++){
     int a=g[i].second.first,
         b=g[i].second.second,
         c=g[i].first;
      if(findSet(a)!=findSet(b)){
        cost+=c;
        res.push_back(g[i].second);
        unionSet(a,b);
      }
   }

   cout<<cost<<endl;

   for(int i=0;i<res.size();i++)
      cout<<res[i].first+1<<" "<<res[i].second+1<<endl;  //For correct indexing

}
