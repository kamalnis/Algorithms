#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t,k;
    cin>> t;
    k=t;
    while(t--){
        int N, P;
        cin>>N>>P;
        vector<int> S(N,0);

        for(int i=0;i<N;i++){
            cin>>S[i];
        }
        sort(S.begin(),S.end());
        int min_val= INT_MAX;
        for(int i=P-1;i<N;i++){
            int current_count=0;
            for(int j=i-(P-1);j<=i;j++){
                current_count+=S[i]-S[j];

            }
            if(current_count<min_val)
                min_val = current_count;
        }
        cout<<"Case #"<<k-t<<":"<<" "<<min_val<<endl;
    }

}