#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include <algorithm>

using namespace std;
int memo[5201];
int main()
{
    int m;
    cin >> m;
    vector<string> names;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin>>str;
        names.push_back(str);
    }
    sort(names.begin(), names.end());
    // for(int i=0;i<names.size();i++){
    //     cout<<names[i]<<endl;
    // }
    // for (int i = 1; i <= m; i++)
    // {
    //     memo[i]=0;
    //     int n = names[i].length();
    //     char char_array[n + 1];
    //     strcpy(char_array, names[i].c_str());
    //     for (int j = 0; j < n; j++)
    //     {
    //         memo[i]+=(char_array[j]-'A'+1)*i;
    //     }
    // }
    int q;
    cin>>q;
    while(q--){
        string query;
        cin>>query;
        vector<string>::iterator it;
        int val=0;
            it=find(names.begin(),names.end(),query);
            string name=*it;
            int n = name.length();
            char char_array[n + 1];
            strcpy(char_array, name.c_str());
            int index=distance(names.begin(), it);
           // cout<<"Nis1"<<index<<endl;  
            
            for (int j = 0; j < n; j++)
            {
               val+=(char_array[j]-'A'+1)*(index+1);
            }

        
        cout<<val<<endl;
    }

}