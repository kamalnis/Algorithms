#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
//#include<bits/stdc++.h> 

using namespace std;

int update(vector<vector<int> > &dist,int a, int b,int R, int C){
        int max_val=INT_MIN;
        for(int i=0;i<R;i++){
            for(int j=0; j<C;j++){
               int k = abs(a-i) + abs(b-j);
                if(k<dist[i][j]){
                    dist[i][j]=k;
                    
                }
                if(max_val<dist[i][j])
                    max_val=dist[i][j];
                
            }
        }
        return max_val;
}

void printDist(vector<vector<int> > &dist,int R, int C){
    for(int i=0;i<R;i++){
            for(int j=0; j<C;j++){
               cout<<dist[i][j]<<" ";
            }
            cout<<endl;
    }
}

int main(){
    int t,k;
    cin>> t;
    k=t;
    while(t--){
        int R,C;
        cin>>R>>C;
        vector<vector<int> > myvec(R,vector<int> (C,0));
        vector<vector<int> > dist(R,vector<int> (C,INT_MAX));
        string str;
        for(int i=0;i<R;i++){
            cin>>str;
            for(int j=0; j<str.size();j++){
                myvec[i][j]=str[j]-'0';
                //cout<<myvec[i][j]<<endl;
            }
        }

        for(int i=0;i<R;i++){
            for(int j=0; j<C;j++){
                if(myvec[i][j]==1){
                    update(dist,i,j,R,C);
                }
            }
        }
        //printDist(dist,R,C);
        int max_i= INT_MIN, max_j=INT_MIN, max_val=INT_MAX;
        for(int i=0;i<R;i++){
            for(int j=0; j<C;j++){
                
                if(myvec[i][j]!=1){
                    vector<vector<int> > tempvec(R,vector<int> (C,0));
                    for(int a=0;a<R;a++){
                        for(int b=0;b<R;b++){
                            tempvec[a][b]=dist[a][b];
                        }
                    }
                    int val=update(tempvec,i,j,R,C);
                    //cout<<val<<endl;
                    if(val<max_val){
                        max_val=val;
                    }
                }
            }
        }
        if(max_val==INT_MAX){
            max_val=0;
        }
        cout<<"Case #"<<k-t<<":"<<" "<<max_val<<endl;
    }

}