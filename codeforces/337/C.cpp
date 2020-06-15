#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 9;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    if (m <= n % k)
    {
        cout << m << endl;
        return 0;
    }
    else
    {
        ll tmp = m;
        tmp -= (n % k);
        ll slot = n / k;
        tmp -= ((k - 1) * slot);
        if (tmp <= 0)
        {
            // cout << "yo\n";
            cout << m << endl;
            return 0;
        }
        ll dobel = tmp;
        ll ans = modpow(2,dobel + 1);
        ans = sub(ans,2);
        ans = mul(ans,k);
        // cout << ans << endl;
        ll single = m - (k * dobel);
        ans = add(ans,single);
        cout << ans << endl;
    }
    return 0;
}