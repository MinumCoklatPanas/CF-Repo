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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> adj[1010];
int depth[1010];
int par[1010];
bool vis[1010];
bool vis2[1010];
int n,m;

void dfs(int u)
{
    depth[u] = depth[par[u]] + 1;
    vis[u] = 1;
    vis2[u] = 1;
    for (auto it : adj[u]) if (!vis2[it])
    {
        par[it] = u;
        dfs(it);
    }
}

int findMax(int root)
{
    memset(depth,0,sizeof(depth));
    memset(par,0,sizeof(par));
    memset(vis2,0,sizeof(vis2));
    depth[0] = -1;
    dfs(root);
    int mx = -1;
    int simpan = -1;
    for (int j = 1 ; j <= n ; j++) if (depth[j] > mx && vis2[j])
    {
        mx = depth[j];
        simpan = j;
    }
    return simpan;
}

pair<int,int> findMid(int root)
{
    int simpan = findMax(root);
    simpan = findMax(simpan);
    int mx = depth[simpan];
    int naik = (mx / 2) + (mx % 2);
    if (mx != 0)
    {
        for (int j = 1 ; j <= naik ; j++)
            simpan = par[simpan];
    }
    return make_pair(naik,simpan);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector< pair<int,int> > rep;
    for (int i = 1 ; i <= n ; i++) if (!vis[i])
    {
        rep.push_back(findMid(i));
    }
    sort(rep.begin(),rep.end());
    reverse(rep.begin(),rep.end());
    int curRoot = rep[0].second;
    vector< pair<int,int> > edges;
    for (int i = 1 ; i < rep.size() ; i++)
    {
        edges.push_back({curRoot, rep[i].second});
        adj[curRoot].push_back(rep[i].second);
        adj[rep[i].second].push_back(curRoot);
        curRoot = findMid(curRoot).second;
    }
    int mx = findMax(curRoot);
    mx = findMax(mx);
    cout << depth[mx] << endl;
    for (auto it : edges)
        cout << it.first << " " << it.second << endl;
    return 0;
}