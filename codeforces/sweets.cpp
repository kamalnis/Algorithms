#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n,0);

    map<int,int> mymap;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            mymap[a[i]+a[j]]++;
        }
    }

    int max=-1;

    for(map<int,int>::iterator it=mymap.begin();it!=mymap.end();it++){
        if(it->second>max){
            max=it->second;
        }
    }
    cout<<max<<endl;
}