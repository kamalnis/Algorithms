#include<iostream>
#include<vector>

using namespace std;

int main(){

    int m,k,n,s;
    cin>>m>>k>>n>>s;

    vector<int> liana(m);
    vector<int> b(s);
    vector<int> pos;

    for(int i=0;i<m;i++){
        cin>>liana[i];
    }

    for(int i=0;i<s;i++){
        cin>>b[i];
    }

    if((n-1) >= (m-s)/k){
        cout<<-1<<endl;
    }
    else{
        int k=0;
        
        for(int i=0;i<m;i++){
            for(int j=k;j<m;j++){
                if(b[j]==liana[i]){
                    pos.push_back(i);
                    k++;
                    break;
                }
            }

        }
        if(k!=s){
            cout<<-1<<endl;
        }
        else{
            
        }

        

    }
}