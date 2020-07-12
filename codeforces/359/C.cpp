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

ll tab[100010];
ll sum[100010];
map<ll,ll> mp;
ll n,x;

bool cek(ll k)
{
    mp.clear();
    for (ll i = 1 ; i <= n ; i++) if (sum[i] < k)
    {
        ll tmp = sum[i];
        mp[tmp]++;
        while (mp[tmp] == x)
        {
            mp[tmp] = 0;
            mp[tmp + 1]++;
            tmp++;
        }  
    }
    for (auto it : mp)
    {
        // cout << it.first << " " << it.second << endl;
        if (it.first < k && it.second > 0) return false;
    }
    return true;
}

ll mul(ll x,ll y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll modpow(ll x,ll y)
{
    if (!y) return 1ll;
    ll z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ll tot = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        tot += tab[i];
    }
    // if (tot == 0)
    // {
    //     cout << 1 << endl;
    //     return 0;
    // }
    for (ll i = 1 ; i <= n ; i++)
        sum[i] = tot - tab[i];
    // cout << cek(4) << endl;
    // return 0;
    ll l = 0;
    ll r = tot;
    while (r - l > 1)
    {
        ll mid = (l + r) >> 1ll;
        if (cek(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (cek(r))
        cout << modpow(x,r) << endl;
    else
        cout << modpow(x,l) << endl;
    return 0;
}