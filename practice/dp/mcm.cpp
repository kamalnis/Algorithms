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


int mat[1000][1000],s[1000][1000];

int mcm(vector<int> &p,int n){
    for(int i=1;i<=n;i++)
        mat[i][i]=0;

    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
              int j=i+l-1,q;
              mat[i][j]=1e9;
              for(int k=i;k<=j-1;k++){
                q=mat[i][k]+mat[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<mat[i][j]){
                  mat[i][j]=q;
                  s[i][j]=k;
                }
              }
        }
    }
    return mat[1][n];
}
void print_parenthesis(int i,int j){
    if(i==j)
        printf("A");
    else{
        printf("(");
        print_parenthesis(i,s[i][j]);
        print_parenthesis(s[i][j]+1,j);
        printf(")");

    }

}

int main(){
   int arr[] = {1, 2, 3, 4};
   vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
   cout<<mcm(vec,3)<<endl;

   print_parenthesis(1,3);


}
