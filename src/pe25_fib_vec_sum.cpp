#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
vector<vector <int> > fib(5001);

vector<int> vec_sum(vector<int> &a, vector<int> &b){
    vector<int> c;
    for(int i=0;i<a.size()|| i<b.size();i++){
        if(i<b.size() && i<a.size() ){
            int k=a[i]+b[i];
            c.push_back(k);
        }
        else if(i<b.size()){
            c.push_back(b[i]);
        }
        else{
            c.push_back(a[i]);
        }
    }
    int temp=0;
    for(int i=0;i<c.size();i++){
        c[i]+=temp;
        temp=c[i];
        c[i]=temp%10;
        temp=temp/10;
    }
    if(temp!=0)
        c.push_back(temp);

    return c;
}
int main(){
    //Memoization
    fib[0].push_back(1);
    fib[1].push_back(1);
    int curr_size=1;
    map<int,int> mymap;
    mymap[1]=1;
    int i=3;
    while(fib[1].size()<=5000){
        vector<int> temp=fib[1]; 
        fib[1]=vec_sum(fib[0],fib[1]);
        fib[0]=temp;
       // cout<<fib[1].size()<<endl;
        if(fib[1].size()>curr_size){
            mymap[curr_size+1]=i;
            curr_size++;
        //    cout<<fib[i].size()<<endl;
        }
        i++;
    }
   // cout<<"Nis"<<endl;
    //Actual code starts
    int t=0;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<mymap[n]<<endl;
    }



}