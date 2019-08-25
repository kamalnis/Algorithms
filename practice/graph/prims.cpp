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

vector<pair<int,int> > g[3000];
int main(){
    int n,e,s;
    cin>>n>>e;

    for(int i=0;i<e;i++){
      int a,b,c;
      cin>>a>>b>>c;
      g[a].push_back(make_pair(b,c));
      g[b].push_back(make_pair(a,c));
    }
    cin>>s;
    vector<int> min_e(n+1,INF),sel_e(n+1,-1);
    vector<bool> used(n+1,false);
    min_e[s]=0;
    set<pair<int,int> > q;
        int sum=0;
    q.insert(make_pair(0,s));
    for(int i=0;i<n;i++){
      if(q.empty()){
        cout<<"No MST!";
        break;
      }
      int v=q.begin()->second;
      sum+=q.begin()->first;
      q.erase(q.begin());
      used[v]=true;

     if(sel_e[v]!=-1)
           cout<<v<<" "<<sel_e[v]<<endl;

      for(int j=0;j<g[v].size();j++){
        int to=g[v][j].first, cost=g[v][j].second;
        if(!used[to])
        if(cost<min_e[to]){
          q.erase(make_pair(min_e[to],to));
          min_e[to]=cost;
          sel_e[to]=v;
          q.insert(make_pair(min_e[to],to));
        }
      }
    }

  //  for(int i=0;i<min_e.size();i++)
    //  sum+=min_e[i];

    cout<<sum;

}
