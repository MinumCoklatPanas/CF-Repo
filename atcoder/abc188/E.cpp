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

int dp[2][200010];
vector<int> adj[200010];
bool vis[2][200010];
int tab[200010];

int rec(int dah,int ix)
{
    // cout << dah << " " << ix << endl;
    if (vis[dah][ix]) return dp[dah][ix];
    if (adj[ix].size() == 0)
    {
        if (dah == 0) return -INFF;
        if (dah == 1) return tab[ix];
    }
    vis[dah][ix] = 1;
    int ret = -INFF;
    if (dah == 0)
    {
        for (auto it : adj[ix])
        {
            ret = max(ret,rec(dah,it));
            ret = max(ret,-tab[ix] + rec(1,it));
        }
    }
    else
    {
        for (auto it : adj[ix])
        {
            ret = max(ret,rec(dah,it));
            ret = max(ret,tab[ix]);
        }
    }
    return dp[dah][ix] = ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = -INFF;
    for (int i = 1 ; i <= n ; i++) ans = max(ans,rec(0,i));
    cout << ans << endl;
    return 0;
}