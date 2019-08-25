#include<iostream>
typedef long long ll;
using namespace std;
//This function calculate days from 1 Jan 1900
ll ly_months[12]={31,29,31,30,31,30,31,31,30,31,30,31};
ll nly_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};

ll calc_days(ll d,ll m,ll y){
    ll a=(y-1)/400;
    ll b=(y-1)/100;
    ll c=(y-1)/4;
    ll totLY=c-b+a;
    ll tot_days=totLY*366+(y-1-totLY)*355-861495;
    // if(y%400==0 || (y%100!=0 && y%4==0)){
    //     for(ll i=1;i<m;i++){
    //         tot_days+=ly_months[i-1];
    //     }
    //     tot_days+=d;
    // }
    // else{
    //     for(ll i=1;i<m;i++){
    //         tot_days+=nly_months[i-1];
    //     }
    //     tot_days+=d; 
    // }
    return tot_days;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll d1,m1,y1,d2,m2,y2;
        ll sunday=0;
        cin>>y1>>m1>>d1>>y2>>m2>>d2;
        if(m1==1){
            
        }
        for(ll i=y1+1;i<y2;i++){

        }

    }
}