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

ll mul(ll a, ll b){
   ll res = 0;
   for(;b; b>>=1, a <<=1){
       if(a>=MOD) a-=MOD;
       if(b&1){
           res+=a;
           if(res>=MOD) res-=MOD;
       }
   }
   return res;
}

ll add(ll x,ll y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

ll modpow(ll x,ll y)
{
    if (!y) return 1;
    ll z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    // cout << z << endl;
    return z;
}

ll g(ll a,ll b)
{
    ll ret = 1;
    while (a % b == 0)
    {
        a /= b;
        ret *= b;
    }
    // cout << a << " " << b << " " << ret << endl;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    vector<ll> primes;
    for (ll i = 2 ; i <= 1000000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (ll j = i + i ; j <= 1000000 ; j += i)
            isPrime[j] = 0;
    }
    ll x,n;
    cin >> x >> n;
    // cout << x << " " << n << endl;
    vector<ll> factors;
    ll tmp = x;
    for (ll i = 0 ; primes[i] * primes[i] <= tmp ; i++) if (tmp % primes[i] == 0)
    {
        factors.push_back(primes[i]);
        while (tmp % primes[i] == 0)
            tmp /= primes[i];
    }
    if (tmp >= 2)
        factors.push_back(tmp);
    // ll ans = 1;
    // for (int i = 1 ; i <= n ; i++)
    // {
    //     ll tmp2 = 1;
    //     for (auto it : factors)
    //     {
    //         // cout << it << " ";
    //         tmp2 *= g(i,it);
    //         ans = mul(ans,g(i,it));
    //     }
    //     // cout << endl;
    //     cout << i << " " << tmp2 << endl;
    // }
    ll ans = 1;
    for (auto it : factors)
    {
        tmp = n;
        ll cnt = 0;
        ll cur = it;
        while (cur <= tmp)
        {
            tmp /= cur;
            cnt += tmp;
        }
        // cnt %= MOD - 2;
        // cout << cur << endl;
        // cout << it << " " << cnt << endl;
        ans = mul(ans,modpow(it,cnt));
    }
    cout << ans << endl;
    return 0;
}