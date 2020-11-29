#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long

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

int cnt(int x)
{
    return x / 3;
}

int dp[200010][3];

int cei(int x,int y)
{
    if (x < 0) return 0;
    return (x / y) + (x % y != 0);
}

int cnt(int mod,int l,int r)
{
    // cout << mod << " " << (r - mod) / 3 << " " << max(0ll,cei((l - mod),3))<< endl;
    if (r < mod) return 0;
    return ((r - mod) / 3) - max(0ll,cei((l - mod),3)) + 1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,l,r;
    cin >> n >> l >> r;
    int frek[3];
    for (int i = 0 ; i < 3 ; i++) frek[i] = cnt(i,l,r),dp[1][i] = frek[i]; 
    // cout << dp[1][0] << " " << dp[1][1] << " " << dp[1][2] << endl;
    for (int i = 2 ; i <= n ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
            for (int k = 0 ; k < 3 ; k++)
            {
                // cout << j << " " << k << " " << (j + k) % 3 << " " << j + k << " " << dp[i - 1][j] << " " << frek[k] << endl;
                dp[i][(j + k) % 3] = add(dp[i][(j + k) % 3],mul(dp[i - 1][j],frek[k]));
            }
    }
    cout << dp[n][0] << endl;
    return 0;
}