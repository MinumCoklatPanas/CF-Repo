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
#define MULTI_TC 0

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int sub(int x,int y)
{
    int ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0) ret += MOD;
    return ret;
}

int mul(int x,int y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

int modpow(int x,int y)
{
    if (!y) return 1;
    int z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1)
        z = mul(z,x);
    return z;
}

int inverse(int x)
{
    return modpow(x,MOD - 2);
}

int bagi(int x,int y)
{
    return mul(x,inverse(y));
}

void solve()
{
    int n,x;
    cin >> n >> x;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    int r = mul(n,modpow(2,x));
    int l = add(sub(r,modpow(2,x)),1);
    // cout << l << " " << r << endl;
    int ret = add(l,r);
    // ret = mul(ret,modpow(2,x));
    // ret = bagi(ret,modpow(2,x));
    cout << ret << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}