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

vector<int> adj[100010];
int spa[20][100010];
int depth[100010];
int sz[1000010];
const int LOG = 20;
int n;

void dfs(int u,int prv)
{
    sz[u] = 1;
    for (auto it : adj[u]) if (it != prv)
    {
        spa[0][it] = u;
        depth[it] = depth[u] + 1;
        dfs(it,u);
        sz[u] += sz[it];
    }
}

void build()
{
    memset(spa,-1,sizeof(spa));
    dfs(1,-1);
    for (int i = 1 ; i < LOG ; i++)
    {
        for (int j = 1 ; j <= n ; j++) if (spa[i - 1][j] != -1)
            spa[i][j] = spa[i - 1][spa[i - 1][j]];
    }
}

int getLCA(int u,int v)
{
    if (depth[u] < depth[v]) swap(u,v);
    for (int i = LOG - 1 ; i >= 0 ; i--) if (depth[u] - (1 << i) >= depth[v])
        u = spa[i][u];
    if (u == v) return u;
    for (int i = LOG - 1 ; i >= 0 ; i--) if (spa[i][u] != -1 && spa[i][u] != spa[i][v])
    {
        u = spa[i][u];
        v = spa[i][v];
    } 
    return spa[0][u];
}

int naik(int u,int k)
{
    assert(depth[u] >= k);
    for (int i = 0 ; i < LOG ; i++) if (k & (1 << i)) u = spa[i][u];
    return u;
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
    build();
    int q;
    cin >> q;
    while (q--)
    {
        int u,v;
        cin >> u >> v;
        if (u == v)
        {
            cout << n << endl;
            continue;
        }
        int lca = getLCA(u,v);
        int dist = depth[u] + depth[v] - 2 * depth[lca] + 1;
        if (dist % 2 == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (depth[u] == depth[v])
        {
            int jarak = depth[u] - depth[lca];
            u = naik(u,jarak - 1);
            v = naik(v,jarak - 1);
            int ans = n - sz[u] - sz[v];
            cout << ans << endl;
        }
        else
        {
            int distToPoint = (dist) / 2;
            int uToLCA = depth[u] - depth[lca];
            int vToLCA = depth[v] - depth[lca];
            if (uToLCA < vToLCA) swap(u,v);
            // cerr << u << " " << v << " " << distToPoint << endl;
            // return;
            int point = naik(u,distToPoint);
            int excluded = naik(u,distToPoint - 1);
            int ans = sz[point] - sz[excluded];
            cout << ans << endl;
        }   
    }
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