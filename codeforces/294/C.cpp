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

ll modpow(ll x,ll y)
{
    if (!y) return 1;
    ll z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

ll pan[1010];
ll fak[1010];

ll inv(ll x)
{
    return modpow(x,MOD - 2);
}

ll comb(ll x,ll y)
{
    ll atas = fak[x];
    ll bawah = mul(fak[x - y],fak[y]);
    bawah = inv(bawah);
    ll ret = mul(atas,bawah);
    return ret;
}

ll tab[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ll a = ((-4) % 3);
    // cout << a << endl;
    pan[0] = 1;
    fak[0] = 1;
    for (ll i = 1 ; i <= 1000 ; i++)
    {
        pan[i] = mul(pan[i - 1],2ll);
        fak[i] = mul(fak[i - 1],1ll * i);
    }
    ll n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
        cin >> tab[i];
    sort(tab + 1,tab + m + 1);
    ll bef = 0;
    ll cur = n - m;
    ll ans = 1;
    for (ll i = 1 ; i <= m ; i++)
    {
        ll ta = tab[i];
        // cin >> ta;
        ll dist = ta - bef - 1;
        ans = mul(ans,comb(cur,dist));
        // cout << cur << " " << dist << endl;
        cur -= dist;
        if (i > 1 && dist > 0)
            ans = mul(ans,pan[dist - 1]);
        // cout << ans << endl;
        bef = ta;
    }
    cout << ans << endl;
    return 0;
}