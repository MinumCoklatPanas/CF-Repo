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

int tab[110];
int cost[110][110];
int dp[110][110][110];
int n,m,k;

int rec(int bef,int ix,int part)
{
    // cout << bef << " " << ix << " " << part << endl;
    if (ix > n)
    {
        if (part != k) return INFF;
        else return 0;
    }
    if (part > k) return INFF;
    if (dp[bef][ix][part] != -1) return dp[bef][ix][part];
    int ret = INFF;
    if (tab[ix] != 0)
    {
        ret = rec(tab[ix],ix + 1,part + (tab[ix] != bef));
    }
    else
    {
        for (int i = 1 ; i <= m ; i++)
        {
            ret = min(ret,cost[ix][i] + rec(i,ix + 1,part + (i != bef)));
        }
    }
    return dp[bef][ix][part] = ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
            cin >> cost[i][j];
    memset(dp,-1,sizeof(dp));
    int ans = rec(0,1,0);
    if (ans == INFF) ans = -1;
    cout << ans << endl;
    return 0;
}