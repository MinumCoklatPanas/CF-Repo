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

int dp[1000010][7];
int n;

int rec(int index,int mask)
{
    if (index > n) return (mask == 3);
    if (dp[index][mask] != -1) return dp[index][mask];
    int ret = rec(index + 1,mask | 1);
    ret = add(ret,rec(index + 1,mask | 2));
    ret = add(ret,rec(index + 1,mask));
    ret = add(ret,rec(index + 1,mask));
    ret = add(ret,rec(index + 1,mask));
    ret = add(ret,rec(index + 1,mask));
    ret = add(ret,rec(index + 1,mask));
    ret = add(ret,rec(index + 1,mask));
    ret = add(ret,rec(index + 1,mask));
    ret = add(ret,rec(index + 1,mask));
    return dp[index][mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> n;
    int ans = rec(1,0);
    cout << ans << endl;
    return 0;
}
