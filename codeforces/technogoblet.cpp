#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> myvec(n);
    map<int,int> student;
    map<int,int> mymap;

    for(int i=0;i<n;i++){
        cin>>myvec[i];
    }
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        student[myvec[i]]=temp;
        if(mymap.find(temp)!=mymap.end()){
            if(myvec[i]>mymap[temp])
                mymap[temp]=myvec[i];
        }
        else
        {
            mymap[temp]=myvec[i];
        }
        
    }
    int count=0;

    for(int i=0;i<k;i++){
        int st;
        cin>>st;
        if(mymap[student[st]]>st){
            count++;
            //cout<<mymap[student[st]]<<" "<<st<<endl;
        }


    }
    cout<<count<<endl;
}