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
int depth[100010];
int par[100010];
int deg[100010];
int child[100010];

void dfs(int u,int prv)
{
    for (auto it : adj[u]) if (it != prv)
    {
        depth[it] = depth[u] + 1;
        par[it] = u;
        child[u]++;
        dfs(it,u);
    }
}

void solve()
{
    int n,k;
    cin >> n >> k;
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        if (deg[i] == 2)
        {
            cout << "No\n";
            return;
        }
    }
    dfs(1,-1);
    int ambil = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        if (depth[i] > depth[ambil])
        {
            ambil = i;
        }
    }
    memset(depth,0,sizeof(depth));
    memset(child,0,sizeof(child));
    dfs(ambil,-1);
    ambil = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        if (depth[i] > depth[ambil])
        {
            ambil = i;
        }
    }
    if (depth[ambil] != 2 * k)
    {
        cout << "No\n";
        return;
    }
    int root = ambil;
    memset(depth,0,sizeof(depth));
    memset(child,0,sizeof(child));
    for (int i = 1 ; i <= k ; i++) root = par[root];
    dfs(root,-1);
    for (int i = 1 ; i <= n ; i++)
    {
        if (child[i] == 2 || child[i] == 1 || (child[i] == 0 && depth[i] != k))
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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