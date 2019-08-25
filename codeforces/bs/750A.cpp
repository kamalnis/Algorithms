#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int remaining_time=240-k;

    int first=1,last=n;
    int count=0;
    while(first<=last){
        int mid= first + (last-first)/2;
        if(5*mid*(mid+1)/2 <= remaining_time){
            count=mid;
            first = mid+1;
        }
        else{
            last=mid-1;
        }
    }
    cout<<count<<endl;
}