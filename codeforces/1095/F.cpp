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

void solve()
{
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) par[i] = i;
    vector< pair<int,pair<int,int> > > edges;
    vector<pair<int,int>> tab(n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> tab[i].first;
        tab[i].second = i + 1;
    }
    sort(tab.begin(),tab.end());
    for (int i = 1 ; i < n ; i++)
    {
        int u = tab[0].second;
        int v = tab[i].second;
        int cost = tab[0].first + tab[i].first;
        edges.push_back({cost,{u,v}});
    }
    for (int i = 0 ; i < m ; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    int ans = 0;
    for (auto it : edges)
    {
        int u = it.second.first;
        int v = it.second.second;
        int w = it.first;
        if (joins(u,v))
            ans += w;
    }
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