#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353;
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

int n,m,k;
int dp[5010][5010];

void solve()
{
    cin >> n >> m >> k;
    vector< pair<int,int> > edge(m);
    for (auto &it : edge) cin >> it.first >> it.second;
    dp[0][1] = 1;
    int prevSum = 1;
    for (int i = 1 ; i <= k ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
            dp[i][j] = prevSum;
        for (int j = 1 ; j <= n ; j++)
            dp[i][j] = sub(dp[i][j],dp[i - 1][j]);
        for (auto it : edge)
        {
            dp[i][it.first] = sub(dp[i][it.first],dp[i - 1][it.second]);
            dp[i][it.second] = sub(dp[i][it.second],dp[i - 1][it.first]);
        }
        prevSum = 0;
        for (int j = 1 ; j <= n ; j++)
            prevSum = add(prevSum,dp[i][j]);
    }
    cout << dp[k][1] << endl;
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