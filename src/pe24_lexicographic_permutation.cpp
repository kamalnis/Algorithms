#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<char> arr;
        vector<char> perm;
        for (int i = 0; i < 13; i++)
        {
            arr.push_back('a' + i);
        }
        for (int i = 13; i >= 1; i--)
        {
            ll fact = 1;
            for (ll j = 1; j <= i-1; j++)
                fact *= j;
            int k = 0;
            while (n-fact> 0)
            {
                n -= fact;
                k++;
            }

            perm.push_back(arr[k]);
            arr.erase(arr.begin()+k);
        }
        for (int i = 0; i < perm.size(); i++)
        {
            cout << perm[i];
        }
        cout << endl;
    }
}