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

vector<pair<int,int>> adj[100010];
int ans[100010];
int tmp;

void dfs(int u,int par)
{
    for (auto it : adj[u]) if (it.first != par)
    {
        ans[it.second] = tmp++;
        dfs(it.first,u);
    }
}

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
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    int mx = 0;
    int simpan = -1;
    for (int i = 1 ; i <= n ; i++)
    {
        if (adj[i].size() > mx)
        {
            mx = adj[i].size();
            simpan = i;
        }
    }
    if (mx < 3)
    {
        for (int i = 0 ; i <= n - 2 ; i++)
            cout << i << endl;
        return 0;
    }
    tmp = 3;
    for (int i = 0 ; i < 3 ; i++)
    {
        ans[adj[simpan][i].second] = i;
        dfs(adj[simpan][i].first,simpan);
    }
    for (int i = 3 ; i < adj[simpan].size() ; i++)
    {
        ans[adj[simpan][i].second] = tmp++;
        dfs(adj[simpan][i].first,simpan);
    }
    for (int i = 1 ; i < n ; i++)
        cout << ans[i] << endl;
    return 0;
}