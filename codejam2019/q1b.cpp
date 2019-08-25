#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
//#include<bits/stdc++.h> 

using namespace std;

int main(){
    int t,k;
    cin>> t;
    k=t;
    while(t--){
        int n;
        cin>>n;
        string str,str1;
        cin>>str;
        str1=str;
        for(int i=0;i<str.size();i++){
            if(str[i]=='S'){
                str1[i]='E';
            }
            else{
                str1[i]='S';
            }
           
        }
        cout<<"Case #"<<k-t<<":"<<" "<<str1<<endl;
        str.clear();
        str1.clear();
    }

}