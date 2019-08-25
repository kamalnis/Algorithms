#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;
vector<string> permstring;
int generatePermutation(map<char,int> &mymap,string &str,int n){

    if(n==0){
        cout<<str<<endl;
        permstring.push_back(str);
        return 0;
    }
/*
    for(auto& x: mymap){
        if(x.second!=0){
            str.push_back(x.first);
            x.second--;
            generatePermutation(mymap,str,n-1);
            x.second++;
            str.pop_back();
        }
    }
    */
    for(map<char,int>::iterator it=mymap.begin();it!=mymap.end();it++){
        if(it->second!=0){
            str.push_back(it->first);
            it->second--;
            generatePermutation(mymap,str,n-1);
            it->second++;
            str.pop_back();
        }
    }
    return 0;



}

int main(){
    string str;
    cout<<"Enter the string = ";
    cin>>str;

    map<char,int> mymap;

    for(int i=0;i<str.length();i++){
        mymap[str[i]]++;
    }
    string permstr;
    generatePermutation(mymap,permstr,str.size());
    cout<<"Number of permutations = "<<permstring.size()<<endl;

}