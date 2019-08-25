#include<iostream>
#include<vector>
using namespace std;

bool util(vector<int> &myarr,int l){
    //cout<<"length:"<<l<<endl;
    int n=(int) myarr.size();
    int count_l=-1;
    
    int check=false;
    for(int i=0;i<=n-l && !check;i++){
        int count=1;
        int fish=myarr[i];
        for(int j=i+1;j<=i+l-1;j++){
            if(fish!=myarr[j]){
                count++;
                fish=myarr[j];
                
            }
            if(count>2){
                break;
            }
        }
        //cout<<"count"<<count<<" i:"<<i<<endl;
        if(count==2){
            if(myarr[(i+l-1)/2]!=myarr[i+l-1]){
                count_l=l;
                check=true;
                break;
            }
        }

    }
    //cout<<count_l<<endl;
    return check;
    
}

int main(){
    int n;
    cin>>n;
    vector<int> myarr(n,0);
    for(int i=0;i<n;i++)
        cin>>myarr[i];

    int first=1,last=n/2;
    int length=0; 
    while(first<=last){
        int mid=first+(last-first)/2;
        //cout<<"mid:"<<mid*2<<endl;
        if(util(myarr,mid*2)){
            length=mid*2;
            first=mid+1;;
        }
        else{
            last=mid-1;
        }
    }
    cout<<length<<endl;
}