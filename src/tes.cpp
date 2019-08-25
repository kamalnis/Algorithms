#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> count_primes(long long n) {
    const int S = 10;
    vector<int> myprimes;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<bool> is_prime(nsqrt + 1, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int i=0;i<primes.size();i++) {
            int p=primes[i];
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            cout<<"k="<<k<<" start_idx="<<start_idx<<" prime="<<p<<" j="<<j<<endl;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                //result++;
                myprimes.push_back(start+i);
        }
    }
    return myprimes;
}
int main(){
    vector<int> myprimes = count_primes(100);
    cout<<"Number of primes="<<myprimes.size()<<endl;
    for(int i=0;i<myprimes.size();i++){
        cout<<myprimes[i]<<" ";
    }
    cout<<endl;
} 