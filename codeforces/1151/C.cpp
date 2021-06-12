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
    if (y & 1) z = mul(z,x);
    return z;
}

int reverse(int x)
{
    return modpow(x,MOD - 2);
}

int bagi (int x,int y)
{
    return mul(x,reverse(y));
}

void solve()
{
    int l,r;
    cin >> l >> r;

    const auto sum = [&](int a,int k) -> int
    {
        int b = add(a,mul((k - 1),2));
        int ret = mul(add(a,b),k);
        ret = bagi(ret,2);
        return ret;
    };

    const auto f = [&](int x) -> int
    {
        int last[2] = {1,2};
        bool cur = 0;
        int ret = 0;
        int rem = x;
        for (int i = 1 ; (1ll << i) - 1 <= x ; i++)
        {
            int len = (1ll << (i - 1));
            ret = add(ret,sum(last[cur],len));
            last[cur] = add(last[cur],mul(2,len));
            cur ^= 1;
            rem -= len;
        }
        // cur ^= 1;
        // cerr << ret << " " << rem << " " << cur << " " << last[cur] << endl;
        if (rem > 0)
        {
            ret = add(ret,sum(last[cur],rem));
        }
        return ret;
    };

    int ans = sub(f(r),f(l - 1));
    cout << ans << endl;
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