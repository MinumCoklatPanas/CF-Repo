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

vector<int> adj[200010];
int dp[200010];
int dp2[200010];
int sz[200010];
int dpSum[200010];
int sumAll;
int ans = 0;
int n;

void dfs1(int u,int par)
{
    sz[u] = 1;
    for (auto it : adj[u]) if (it != par)
    {
        dfs1(it,u);
        sz[u] += sz[it];
        dp[u] += dp[it];
        dpSum[u] += dp[it];
    }
    dp[u] += sz[u];
    dpSum[u] += dp[u];
    // cerr << u << " " << dp[u] << endl;
    sumAll += dp[u];
}


void dfs2(int u,int par)
{
    int tmp = dp2[par] - dp[u];
    tmp -= sz[u];
    tmp += dp[u] + n - sz[u];
    if (u != 1)
        dp2[u] = tmp;
    else
        dp2[u] = dp[u];
    ans = max(ans,dp2[u]);
    for (auto it : adj[u]) if (it != par)
    {
        dfs2(it,u);
    }
}

void solve()
{
    cin >> n;
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0);
    // cerr << "------------------------------\n";
    dfs2(1,0);
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