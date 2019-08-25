#include<iostream>

using namespace std;

int gcdEx(int a,int b,int &x,int &y){
    if(a==0){
      x=0,y=1;
      return b;
    }
    int x1,y1;
    int d=gcdEx(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;


}

int main(){
    int x,y,a,b;
    a=35,b=15;
    int g=gcdEx(a,b,x,y);

    cout<<"GCD of "<<a<<" and "<<b<<" is= "<<g<<endl;
    cout<<"x: "<<x<<" y: "<<y<<endl;
    return 0;

}
