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

ll mul(ll a,ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll add(ll a,ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll modpow(ll x,ll y)
{
    if (!y) return 1;
    ll z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

bool valid(ll k,ll a,ll b)
{
    while (k)
    {
        ll tmp = k % 10;
        if (tmp != a && tmp != b) return 0;
        k /= 10;
    }
    return 1;
}

ll fak[1000010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fak[0] = 1;
    for (ll i = 1 ; i <= 1000000 ; i++)
        fak[i] = mul(fak[i - 1],i);
    ll n,a,b;
    cin >> a >> b >> n;
    ll ans = 0;
    for (ll i = 0 ; i <= n ; i++)   
    {
        ll sum = a * i + b * (n - i);
        if (valid(sum,a,b))
        {
            ll atas = fak[n];
            ll bawah = mul(fak[i],fak[n - i]);
            bawah = modpow(bawah,MOD - 2);
            ans = add(ans,mul(atas,bawah));
        }
    }
    cout << ans << endl;
    return 0;
}