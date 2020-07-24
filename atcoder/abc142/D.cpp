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

bool isPrime[1000010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    vector<ll> primes;
    for (ll i = 1 ; i <= 1000000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (ll j = i + i ; j <= 1000000 ; j += i)
            isPrime[j] = 0;
    }
    ll a,b;
    cin >> a >> b;
    ll fpb = __gcd(a,b);
    // cout << fpb << endl;
    vector<ll> factors;
    for (ll i = 1 ; i * i <= fpb ; i++) if (fpb % i == 0)
    {
        factors.push_back(i);
        if (i * i != fpb)
            factors.push_back(fpb / i);
    }
    ll ans = 1;
    for (ll i = 0 ; primes[i] * primes[i] <= fpb ; i++) if (fpb % primes[i] == 0)
    {
        ++ans;
        while (fpb % primes[i] == 0)
            fpb /= primes[i];
    }
    ans += (fpb >= 2);
    cout << ans << endl;
    return 0;
}