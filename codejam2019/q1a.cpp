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
        string str,str1;
        cin>>str;
        str1=str;
        int length = str.size()-1;
        for(int i=length;i>=0;i--){
            if(str[i]=='4'){
                str[i]='3';
                str1[i]='1';
            }
            else{
                str1[i]='0';
            }
        }
        cout<<"Case #"<<k-t<<":"<<" ";
        for(int i=0;i<str.size();i++){
            cout<<str[i];
        }
        cout<<" ";
        bool toggle = true;
        for(int i=0;i<str1.size();i++){
            if(!toggle){
                cout<<str1[i];
            }
            else if(str1[i]=='1'){
                cout<<str1[i];
                toggle = false;
            }
        }
        cout<<endl;


    }

}