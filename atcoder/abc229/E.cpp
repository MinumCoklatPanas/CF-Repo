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

vector<int> adj[200010];
int par[200010];

int finds(int x)
{
    return (par[x] == x ? x : par[x] = finds(par[x]));
}

int numset;

void joins(int x,int y)
{
    int px = finds(x);
    int py = finds(y);
    if (px == py) return;
    par[px] = py;
    --numset;
}

int ans[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) par[i] = i;
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        if (u > v) swap(u,v);
        adj[u].push_back(v);
    }
    ans[n] = 0;
    numset = 0;
    for (int i = n ; i >= 1 ; i--)
    {
        ans[i] = numset;
        ++numset;
        for (auto it : adj[i])
            joins(i,it);
    }
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << endl;
    return 0;
}