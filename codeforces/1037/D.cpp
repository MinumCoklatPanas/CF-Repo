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

vector<int> adj[200010];
int depth[200010];
int cntDepth[200010];
int parent[200010];

void dfs(int node,int par)
{
    parent[node] = par;
    depth[node] = depth[par] + 1;
    cntDepth[depth[node]]++;
    for (auto it : adj[node]) if (it != par)
    {
        dfs(it,node);
    }
    return;
}

int tab[200010];
int prv[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i];
    dfs(1,0);
    int tmp = 2;
    for (auto it : adj[1])
    {
        prv[tmp++] = 1;
    }
    int cur = tmp;
    for (int i = 2 ; i <= n ; i++)
    {
        if (parent[tab[i]] != prv[i])
        {
            cout << "No\n";
            return 0;
        }
        for (auto it : adj[tab[i]]) if (it != parent[tab[i]])
        {
            prv[cur++] = tab[i];
        }
    }
    cout << "Yes\n";
    return 0;
}