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
#define MULTI_TC 1

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
    int n;
    cin >> n;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<vector<int>> dp(2,vector<int>(n + 5,0));
    int ans = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if (tab[i] == 0)
        {
            dp[0][0] = add(dp[0][0],dp[0][0]);
            dp[0][0] = add(dp[0][0],1);
        }
        else
        {
            //dp[hilang][x] += dp[!hilang][x - 2]
            //dp[hilang][x] += dp[hilang][x]
            //dp[!hilang][x] += dp[!hilang][x - 1]
            //dp[!hilang][x] += dp[!hilang][x]
            dp[1][tab[i]] = add(dp[1][tab[i]],dp[1][tab[i]]);
            dp[0][tab[i]] = add(dp[0][tab[i]],dp[0][tab[i]]);
            if (tab[i] >= 2)
                dp[1][tab[i]] = add(dp[1][tab[i]],dp[0][tab[i] - 2]);
            dp[0][tab[i]] = add(dp[0][tab[i]],dp[0][tab[i] - 1]);
            if (tab[i] == 1)
                dp[1][tab[i]] = add(dp[1][tab[i]],1);
            
        }
        dp[1][tab[i] + 2] = add(dp[1][tab[i] + 2],dp[1][tab[i] + 2]);
        // cerr << dp[0][tab[i]] << " " << dp[1][tab[i]] << endl;
        // ans = add(ans,dp[0][tab[i]]);
        // ans = add(ans,dp[1][tab[i]]);
    }
    for (int i = 0 ; i <= n ; i++)
    {
        ans = add(ans,dp[0][i]);
        ans = add(ans,dp[1][i]);
    }
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