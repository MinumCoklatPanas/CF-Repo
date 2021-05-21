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

bool connect[1010];
pair<int,int> a[1010];
pair<int,int> b[1010];
int jump[1010];
int n,m,w;
int dp[1010][1010];
vector<int> adj[1010];
vector< vector<int> > comps;
bool vis[1010];

int rec(int ix,int rem)
{
    if (ix >= comps.size()) return 0;
    if (dp[ix][rem] != -1) return dp[ix][rem];
    int ret = rec(ix + 1,rem);
    int sumW = 0,sumB = 0;
    for (auto it : comps[ix])
    {
        sumW += a[it].first;
        sumB += a[it].second;
        if (rem >= a[it].first)
            ret = max(ret,a[it].second + rec(ix + 1,rem - a[it].first));
    }
    if (rem >= sumW)
        ret = max(ret,sumB + rec(ix + 1,rem - sumW));
    return dp[ix][rem] = ret;
}

int wSum,bSum;
vector<int> elems;

void dfs(int u)
{
    wSum += a[u].first;
    bSum += a[u].second;
    vis[u] = 1;
    elems.push_back(u);
    for (auto it : adj[u]) if (!vis[it])
        dfs(it);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> w;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].first;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].second;
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ; i++) if (!vis[i])
    {
        wSum = 0;
        bSum = 0;
        elems.clear();
        dfs(i);
        for (auto it : elems)
            b[it] = {wSum,bSum};
        comps.push_back(elems);
    }
    // return 0;
    memset(dp,-1,sizeof(dp));
    int ans = rec(0,w);
    cout << ans << endl;
    return 0;
}