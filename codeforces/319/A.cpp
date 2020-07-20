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

ll mul(ll x,ll y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll add(ll x,ll y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

ll sub(ll x,ll y)
{
    ll ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0)
        ret += MOD;
    return ret;
}

ll modpow(ll x,ll y)
{
    if (!y) return 1;
    ll z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

ll inv(ll x)
{
    return modpow(x,MOD - 2);
}

ll bagi(ll x,ll y)
{
    return mul(x,inv(y));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << bagi(6,3) << endl;
    // return 0;
    string s;
    cin >> s;
    ll n = s.length();
    ll k = n - 1;
    ll ans = 0;
    ll pengali = modpow(2ll,k);
    ll pairCount = 1;
    // ll ans = 0;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s[i] == '1')
        {
            ans = add(ans,mul(pairCount,mul(pengali,pengali)));
        }
        pairCount = mul(pairCount,2ll);
        pengali = bagi(pengali,2ll);
    }
    cout << ans << endl;
    return 0;
}