#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[1010][4][2010];
int n,k;

int rec(int ix,int bef,int cc)
{
    // cout << ix << endl;
    if (ix > n)
    {
        return (cc == k);
    }
    if (dp[ix][bef][cc] != -1) return dp[ix][bef][cc];
    int ret = 0;
    if (bef == 0)
    {
        ret += rec(ix + 1,0,cc);
        ret %= MOD;
        ret += rec(ix + 1,1,cc + 1);
        ret %= MOD;
        ret += rec(ix + 1,2,cc + 1);
        ret %= MOD;
        ret += rec(ix + 1,3,cc + 1);
        ret %= MOD;
    }
    if (bef == 1)
    {
        ret += rec(ix + 1,0,cc);
        ret %= MOD;
        ret += rec(ix + 1,1,cc);
        ret %= MOD;
        ret += rec(ix + 1,2,cc + 2);
        ret %= MOD;
        ret += rec(ix + 1,3,cc);
        ret %= MOD;
    }
    if (bef == 2)
    {
        ret += rec(ix + 1,0,cc);
        ret %= MOD;
        ret += rec(ix + 1,1,cc + 2);
        ret %= MOD;
        ret += rec(ix + 1,2,cc);
        ret %= MOD;
        ret += rec(ix + 1,3,cc);
        ret %= MOD;
    }
    if (bef == 3)
    {
        ret += rec(ix + 1,0,cc + 1);
        ret %= MOD;
        ret += rec(ix + 1,1,cc + 1);
        ret %= MOD;
        ret += rec(ix + 1,2,cc + 1);
        ret %= MOD;
        ret += rec(ix + 1,3,cc);
        ret %= MOD;
    }
    return dp[ix][bef][cc] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    int ret = 0;
    ret += rec(2,0,1);
    ret %= MOD;
    ret += rec(2,1,2);
    ret %= MOD;
    ret += rec(2,2,2);
    ret %= MOD;
    ret += rec(2,3,1);
    ret %= MOD;
    cout << ret << endl;
    return 0;
}