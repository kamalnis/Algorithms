#include<iostream>
#include<string>


using namespace std;

int main(){

    string str;
    int num,sum=0;
    cout<<"Enter the alphanumeric string=";
    //cin>>str;
    getline(cin,str);
    for(int i=0;i<str.length();i++){
       num=0;
       while(str[i]>='0' && str[i]<='9'){
           num=num*10+str[i]-'0';
           i++;
       }
       sum=sum+num;

    }

    cout<<"\nSum of numbers in an alphanumeric string="<<sum<<endl;

    return 0;
}
