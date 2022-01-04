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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 5);
    vector< pair<pair<int,int>,int> > edges;
    for (int i = 1 ; i < n ; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({{u,v},w});
        if (w != -1)
        {
            adj[u].emplace_back(v,__builtin_popcount(w) % 2);
            adj[v].emplace_back(u,__builtin_popcount(w) % 2);
        }
    }
    for (int i = 0 ; i < m ; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v,__builtin_popcount(w) % 2);
        adj[v].emplace_back(u,__builtin_popcount(w) % 2);
    }
    vector<int> col(n + 5,-1);
    const auto dfs = [&](const auto &self,int u) -> bool
    {
        bool ret = 1;
        // cerr << u << " " << col[u] << endl;
        for (auto it : adj[u])
        {
            int nxt = col[u] ^ it.second;
            if (col[it.first] == -1)
            {
                col[it.first] = nxt;
                ret &= self(self,it.first);
            }
            else
            if (col[it.first] != nxt)
            {
                cerr << u << " " << it.first << endl;
                return false;
            }
        }
        return ret;
    };
    bool can = 1;
    for (int i = 1 ; i <= n ; i++) if (col[i] == -1)
    {
        col[i] = 0;
        can &= dfs(dfs,i);
    }
    if (!can)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (auto it : edges)
        {
            if (it.second == -1)
                cout << it.first.first << " " << it.first.second << " " << (col[it.first.first] ^ col[it.first.second]) << endl;
            else
                cout << it.first.first << " " << it.first.second << " " << it.second << endl;
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