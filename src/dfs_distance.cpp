#include<iostream>
#include<set>
#include<list>
#include<queue>

using namespace std;

class Node{
   public:
   set<int> adjacent;
   int distance;
};
int dfs(int S,int *visited,Node *graph);

int dist=0;
int dfs(int S,int *visited,Node *graph){

   if(visited[S]!=1){
       visited[S]=1;
       graph[S].distance=dist;
       set<int> adjacent=graph[S].adjacent;
       for(set<int>::iterator it=adjacent.begin();it!=adjacent.end();it++){
              dist++;
              if(visited[*it]!=1){
                  dfs((int)*it,visited,graph);
              }
              dist--;        
       }
   }
   return 0;
}

void bfs(int S,int *visited,Node *graph){

      
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[S] = 1;
    queue.push_back(S);
 
    set<int>::iterator i;
 
    while(!queue.empty())
    {
        S = queue.front();
        //cout << s << " ";
        queue.pop_front();
 
        set<int> adjacent=graph[S].adjacent;
        dist=graph[S].distance+1;
        for(i = adjacent.begin(); i != adjacent.end(); ++i)
        {
            
            if(!visited[*i])
            {
                visited[*i] = true;
                graph[(int)*i].distance=dist;
                queue.push_back((int)*i);
            }
        }
    }
}


int main(){
  int t,n,m,x,y,S;
  cin>>t;

  while(t--){
     cin>>n>>m;
     int visited[n+1];
     Node graph[n+1];

     for(int i=0;i<=n;i++){
         visited[i]=0;
         graph[i].distance=-1;  
     }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].adjacent.insert(y);
        graph[y].adjacent.insert(x);     
    }     
    cin>>S;
    dist=0; 
    visited[S]=1;
    graph[S].distance=dist;
    bfs(S,visited,graph);

    for(int i=1;i<=n;i++){
       if(i!=S){
         if(graph[i].distance!=-1)
           cout<<graph[i].distance*6<<" ";
         else
           cout<<graph[i].distance<<" ";
       }    

    }
    cout<<endl;
  }  

}
