    #include<iostream>
    #include<cmath>
    #include<map>
    typedef long long ll;
    using namespace std;

    int divisor_sum[1000001];
    map<int,int> d;

    int memoize_divisor_sum(){
        for(int i=2;i<=1000000;i++){
            divisor_sum[i]=1;
            for(int j=2;j<=sqrt((double)i);j++){
                if(i%j==0){
                    if(j!=i/j){
                        divisor_sum[i]+=j;
                        divisor_sum[i]+=i/j;
                    }
                    else{
                        divisor_sum[i]+=j;
                    }
                }
            }

            if(divisor_sum[i]<=1000000)
            if(i==divisor_sum[divisor_sum[i]] && divisor_sum[i]!=i){
                d.insert(make_pair(divisor_sum[i],i));
            }
        }
        return 0;
    }
    int main(){
        memoize_divisor_sum();
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            int sum=0;
            if(n>1)
            for(map<int,int>::iterator it=d.begin();it!=d.end();it++){
                //cout<<it->first<<" "<<it->second<<endl;
                if(it->first <= n){
                    //cout<<it->first<<" "<<it->second<<endl;
                    sum+=it->first;
                }
                if(it->second <= n){
                    //cout<<it->first<<" "<<it->second<<endl;
                    sum+=it->second;
                }
            }
            cout<<sum<<endl;

        }
    }