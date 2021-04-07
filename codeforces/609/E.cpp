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

struct node
{
    int u,v,w,ix;

    node(){};

    bool operator< (node other) const
    {
        return w < other.w;
    }
};


vector<pair<int,int>> adj[200010];
int par[200010];

int finds(int x)
{
    return (par[x] == x ? x : par[x] = finds(par[x]));
} 

bool joins(int x,int y)
{
    int px = finds(x);
    int py = finds(y);
    if (px == py) return 0;
    par[px] = py;
    return 1;
}

int spa[2][20][200010];
int depth[200010];

void dfs(int u,int prv)
{
    // cout << u << " " << depth[u] << endl;
    for (auto it : adj[u]) if (it.first != prv)
    {
        spa[0][0][it.first] = u;
        spa[1][0][it.first] = it.second;
        depth[it.first] = depth[u] + 1;
        dfs(it.first,u);
    }
}

void build(int n)
{
    memset(spa,-1,sizeof(spa));
    depth[1] = 1;
    dfs(1,-1);
    for (int i = 1 ; i < 20 ; i++)
        for (int j = 1 ; j <= n ; j++)
        {
            if (spa[0][i - 1][j] != -1)
            {
                spa[0][i][j] = spa[0][i - 1][spa[0][i - 1][j]];
                spa[1][i][j] = max(spa[1][i - 1][j],spa[1][i - 1][spa[0][i - 1][j]]);
            }
        }
}

int query(int u,int v)
{
    if (depth[u] < depth[v]) swap(u,v);
    // cout << u << " " << v << endl;
    // cout << depth[1] << " " << depth[2] << endl;
    // cout << depth[u] << " " << depth[v] << endl;
    int ret = 0;
    for (int i = 19 ; i >= 0 ; i--) if (depth[u] - (1 << i) >= depth[v])
    {
        ret = max(ret,spa[1][i][u]);
        // cout << u << " u\n";
        // cout << spa[1][i][u] << endl;
        u = spa[0][i][u];
    }
    // cout << ret << endl;
    if (u == v) return ret;
    // cout << "yo\n";
    for (int i = 19 ; i >= 0 ; i--) if (spa[0][i][u] != spa[0][i][v] && spa[0][i][u] != -1)
    {
        ret = max(ret,spa[1][i][u]);
        ret = max(ret,spa[1][i][v]);
        u = spa[0][i][u];
        v = spa[0][i][v];
    }
    ret = max(ret,spa[1][0][u]);
    ret = max(ret,spa[1][0][v]);
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) par[i] = i;
    vector< node > edges(m);
    vector< bool > taken(m,0);
    vector< node > asli(m);
    int cnt = 0;
    for (auto &it : edges)
    {
        cin >> it.u >> it.v >> it.w;
        it.ix = cnt++;
    }
    asli = edges;
    sort(edges.begin(),edges.end());
    int mst = 0;
    for (int i = 0 ; i < m ; i++)
    {
        auto it = edges[i];
        if (joins(it.u,it.v))
        {
            // cout << it.u << " " << it.v << " " << i << endl;
            taken[it.ix] = 1;
            mst += it.w;
            adj[it.u].push_back({it.v,it.w});
            adj[it.v].push_back({it.u,it.w});
        }
    }
    build(n);
    // query(1,2);
    // // cout << query(1,2) << endl;
    // return 0;
    // cout << mst << endl;
    for (int i = 0 ; i < m ; i++)
    {
        if (taken[i])
            cout << mst << endl;
        else
        {
            int mx = query(asli[i].u,asli[i].v);
            // cout << asli[i].u << " " << asli[i].v << endl;
            // cout << mx << " ";
            int ans = mst - mx + asli[i].w;
            cout << ans << endl;
        }
    }
    return 0;
}