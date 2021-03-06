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

int dp[2010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[3] = dp[4] = dp[5] = 1;
    for (int i = 6 ; i <= 2000 ; i++)
    {
        dp[i] = 1;
        for (int j = 3 ; j <= i - 3 ; j++)
        {
            dp[i] = add(dp[i],dp[i - j]);
        }
    }
    int n;
    cin >> n;
    cout << dp[n] << endl;
    return 0;
}