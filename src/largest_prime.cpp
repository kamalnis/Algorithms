#include<iostream>
#include<vector>

typedef long long ll;

using namespace std;
char lp[1000001];
int main(){

	int t;
	vector<char> prime(1000001,true);
	vector<ll> pr;
    prime[0]=prime[1]=false;
    for(int i=2;i<=n;i++)
    	if(prime[i])
    		if(i*111*i<=n)
    			for(int j=i*i;j<=n;j+=i)
    				prime[j]=false;

    for(ll i=0;i<=n;i++)
    	if(prime[i])
    		pr.push_back(i);

	cin>>t;
	while(t--){
		ll n;
		cin>>t;
		ll factor;
		for(ll i=2;i*i<=n;i++){
			while(n%i==0){
				factor=i;
				n/=i;
			}
		}
		if(n>2)
			factor=n;

		cout<<factor<<endl;

	}


}
