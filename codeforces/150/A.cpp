#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

bool isPrime[5000010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    vector< ll > primes;
    for (ll i = 2 ; i <= 5000000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (ll j = i + i ; j <= 5000000 ; j += i)
            isPrime[j];
    }
    vector< ll > factor;
    ll n;
    cin >> n;
    ll simpan = n;
    for (ll i = 0 ; primes[i] * primes[i] <= n ; i++) if (n % primes[i] == 0)
    {
        while (n % primes[i] == 0)
        {
            factor.push_back(primes[i]);
            n /= primes[i];
        }
    }
    if (n >= 2)
        factor.push_back(n);
    // cout << factor.size() << endl;
    if (factor.size() == 2)
        cout << 2 << endl;
    else
    {
        cout << 1 << endl;
        if (factor.size() <= 1)
            cout << 0 << endl;
        else
        {
            ll tmp = factor[0] * factor[1];
            // ll ans = simpan / tmp;
            cout << tmp << endl;
        }
    }
    return 0;
}   