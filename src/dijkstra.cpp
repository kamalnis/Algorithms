#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
int inf=1000000000;

int dijkstra(vector<vector<pair<int,int> > >& g, int n,int s){
	vector<int> d(n,inf),p(n,-1);
	priority_queue<pair<int,int> > q;
	d[s]=0;
	q.push(make_pair(0,s));

    while(!q.empty()){
    	int v=q.top().second;
    	int c_dist=-q.top().first;
    	q.pop();
    	if(c_dist>d[v])
    		 continue;
    	for(int j=0;j<g[v].size();j++){
    		int to=g[v][j].first;
    		int length=g[v][j].second;
    		if(d[v]+length<d[to]){
    			d[to]=d[v]+length;
    			p[to]=v;
    			q.push(make_pair(-(int)d[to],to)); //We have to push negative value because priority_queue is of Max type 
    		}
    	}
    }
    for(int i=1;i<n;i++){
    	if(i!=s){
    		if(d[i]==inf)
    			cout<<-1<<" ";
    		else
    			cout<<d[i]<<" ";
    	}
    }
    return 0;
}
int main(){


	int t;
	cin>>t;
	while(t--){

		int n,m,x,y,r,s;
		cin>>n>>m;
		n=n+1;//for index 1 to n
		vector<vector<pair<int,int> > > g(n);
		for(int i=0;i<m;i++){
			cin>>x>>y>>r;
			g[x].push_back(make_pair(y,r));
			g[y].push_back(make_pair(x,r));
		}
		cin>>s;
		dijkstra(g,n,s);
		cout<<"\n";
	}

}
