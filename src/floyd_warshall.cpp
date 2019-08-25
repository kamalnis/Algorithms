#include<iostream>

using namespace std;

int main(){
    int graph[4][4]={{0,   5,  INT_MAX, 10},
                   {INT_MAX,  0,  3,  INT_MAX},
                   {INT_MAX, INT_MAX, 0,   1},
                   {INT_MAX, INT_MAX, INT_MAX, 0}
                };
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX && graph[i][k]+graph[k][j]<graph[i][j])
                    graph[i][j]=graph[i][k]+graph[k][j];
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
}