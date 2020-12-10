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

int dp[2][100010];
int pref[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,k;
    cin >> t >> k;
    dp[0][1] = 1;
    dp[1][1] = (k == 1);
    for (int i = 2 ; i <= 100000 ; i++)
    {
        dp[0][i] = add(dp[0][i - 1],dp[1][i - 1]);
        if (i == k)
            dp[1][i] = 1;
        else
        if (i > k)
        {
            dp[1][i] = add(dp[0][i - k],dp[1][i - k]);
        }
    }
    for (int i = 1 ; i <= 100000 ; i++)
    {
        pref[i] = add(dp[0][i],dp[1][i]);
        // if (i < 5)
        //     cout << pref[i] << 
        pref[i] = add(pref[i - 1],pref[i]);
    }
    while (t--)
    {
        int l,r;
        cin >> l >> r;
        int ans = sub(pref[r],pref[l - 1]);
        cout << ans << endl;
    }
    return 0;
}