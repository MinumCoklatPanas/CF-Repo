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
#define MULTI_TC 1

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
int sz[100010];
int par[100010];
int n;

void dfs(int u,int prv)
{
    sz[u] = 1;
    for (auto it : adj[u]) if (it != prv)
    {
        par[it] = u;
        dfs(it,u);
        sz[u] += sz[it];
    }
}

void solve()
{
    cin >> n;
    for (int i = 1 ; i <= n ; i++) adj[i].clear();
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    int opt = INF;
    for (int i = 1 ; i <= n ; i++)
    {
        int res = n - sz[i];
        int mx = res;
        for (auto it : adj[i]) if (it != par[i])
        {
            mx = max(mx,sz[it]);
        }
        opt = min(opt,mx);
    }
    vector<int> centroids;
    for (int i = 1 ; i <= n ; i++)
    {
        int res = n - sz[i];
        int mx = res;
        for (auto it : adj[i]) if (it != par[i])
        {
            mx = max(mx,sz[it]);
        }
        if (mx == opt) centroids.push_back(i);
    }
    // cerr << centroids.size() << endl;
    // return;
    if (centroids.size() == 1)
    {
        cout << 2 << " " << par[2] << endl;
        cout << 2 << " " << par[2] << endl;
    }
    else
    {
        // cerr << centroids[0] << " " << centroids[1] << endl;
        // return;
        assert(centroids.size() == 2);
        if (par[centroids[1]] != centroids[0]) swap(centroids[0],centroids[1]);
        assert(par[centroids[1]] == centroids[0]);
        // return;
        vector<pair<int,int>> tmp;
        for (auto it : adj[centroids[0]]) if (it != centroids[1])
        {
            tmp.push_back({sz[it],it});
        }
        // cerr << "yo\n";
        // return;
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        cout << centroids[0] << " " << tmp[0].second << endl;
        cout << tmp[0].second << " " << centroids[1] << endl;
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