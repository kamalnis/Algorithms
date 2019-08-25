#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
     char str[100],pat[50];
     cout<<"\nEnter the string=";
     cin>>str;
     cout<<"\nEnter the pattern to search=";
     cin>>pat;
     int n=strlen(str);
     int m=strlen(pat);
 
     int dfa[m+1][256];
     for(int i=0;i<256;i++)
         dfa[0][i]=0;

     dfa[0][pat[0]]=1;

     int pre_suf=0;

     for(int i=1;i<=m;i++){
         for(int j=0;j<256;j++)
              dfa[i][j]=dfa[pre_suf][j];
 
         dfa[i][pat[i]]=i+1;
         if(i<m)
            pre_suf=dfa[pre_suf][pat[i]];
     }

     int state=0;
     for(int i=0;i<n;i++){
        state=dfa[state][str[i]];
        if(state == m)
           cout<<"\nPattern matches at "<<i-m+1; 
     }

}