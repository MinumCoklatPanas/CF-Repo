#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pref[2][100010];

int get(int k,int l,int r)
{
    return pref[k][r] - pref[k][l - 1];
}

int mul(int x,int y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int sub(int x,int y)
{
    int ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0)
        ret += MOD;
    return ret;
}

int modpow(int x,int y)
{
    if (!y) return 1;
    int z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

int inv(int x)
{
    return modpow(x,MOD - 2);
}

int bagi(int x,int y)
{
    return mul(x,inv(y));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 1 ; i <= n ; i++)
    {
        pref[0][i] = pref[0][i - 1];
        pref[1][i] = pref[1][i - 1];
        char ta;
        cin >> ta;
        pref[ta - '0'][i]++;
    }
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        int nol = get(0ll,l,r);
        int satu = get(1ll,l,r);
        int ans = sub(modpow(2ll,satu),1ll);
        ans = mul(ans,modpow(2ll,nol));
        cout << ans << endl;
    }
    return 0;
}