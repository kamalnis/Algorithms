#include<iostream>
#include<vector>

using namespace std;

vector<int> t;

void build(vector<int> &a,int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
    }
    else{
        int tm = tl + (tr-tl)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}

int sum(int v,int tl,int tr,int l,int r){
    if(l>r) 
        return 0;
    else if(tl==l && tr==r){
        return t[v];
    }
    else{
        int tm=tl + (tr-tl)/2;
        return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
}

void update(int v,int tl,int tr,int pos,int new_val){
    if(tl==tr){
        t[v]=new_val;
    }
    else{
        int tm = tl + (tr-tl)/2;
        if(pos<=tm)
            update(v*2,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v]=t[v*2]+t[v*2+1];

    }
}

int main(){
    int n;
    cin>>n;
    t.resize(4*n,0);
    vector<int> a(n,0);
    //cout<<"Enter the element of the array:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(a,1,0,n-1);
    cout<<"\nSum in range 1 to 3 = "<<sum(1,0,n-1,0,4)<<endl;
    update(1,0,n-1,2,4);
        cout<<"\nSum in range 1 to 3 = "<<sum(1,0,n-1,1,3)<<endl;
    
}