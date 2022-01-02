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
    int n,k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 5);
    vector<bool> special(n + 5,0);
    vector<int> depth(n + 5,0);
    vector<int> parent(n + 5,0);
    vector<int> degree(n + 5,0);
    for (int i = 0 ; i < k ; i++)
    {
        int ta;
        cin >> ta;
        special[ta] = 1;
    }
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++; degree[v]++;
    }
    const auto dfs = [&](const auto &self,int u,int par) -> void
    {
        for (auto it : adj[u]) if (it != par)
        {
            parent[it] = u;
            depth[it] = depth[u] + 1;
            self(self,it,u);
        }
    };
    dfs(dfs,1,-1);
    queue<int> leaves;
    for (int i = 2 ; i <= n ; i++) if (adj[i].size() == 1)
        leaves.push(i);
    vector<int> nearestSpecial(n + 5,INF);
    vector<bool> marked(n + 5,0);
    vector<bool> vis(n + 5,0);
    while (!leaves.empty())
    {
        int cur = leaves.front();
        leaves.pop();
        // cerr << cur << endl;
        if (cur == 1) continue;
        if (special[cur])
        {
            marked[cur] = 1;
            nearestSpecial[cur] = 0;
        }
        else
        {
            int mn = INF;
            for (auto it : adj[cur]) if (it != parent[cur]) mn = min(mn,nearestSpecial[it] + 1);
            nearestSpecial[cur] = mn;
        }   
        if (nearestSpecial[cur] <= depth[cur]) marked[cur] = 1;
        --degree[parent[cur]];
        if (degree[parent[cur]] == 1)
        {
            leaves.push(parent[cur]);
        }
        // cerr << cur << ": " << marked[cur] << endl;
    }
    const auto dfs2 = [&](const auto &self,int u) -> int
    {
        if (marked[u]) return 1;
        if (adj[u].size() == 1 && u != 1) return -INF;
        int ret = 0;
        for (auto it : adj[u]) if (it != parent[u]) ret += self(self,it);
        return ret;
    };
    int ans = max(-1ll,dfs2(dfs2,1));
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