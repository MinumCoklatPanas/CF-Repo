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
int sz[200010];

int finds(int x)
{
    return (par[x] == x ? x : par[x] = finds(par[x]));
}

int cnt = 0;

int f(int x)
{
    return (x * (x + 1)) / 2;
}

void joins(int x,int y)
{
    int px = finds(x);
    int py = finds(y);
    if (px == py) return;
    int sx = sz[px];
    int sy = sz[py];
    cnt -= f(sx);
    cnt -= f(sy);
    par[px] = py;
    sz[py] += sz[px];
    cnt += f(sx + sy);
}

void solve()
{
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) par[i] = i,sz[i] = 1;
    vector< pair< int,pair<int,int> > > tab(n - 1);
    for (auto &it : tab)
    {
        cin >> it.second.first >> it.second.second >> it.first;
    }
    sort(tab.begin(),tab.end());
    vector< pair<int,int> > query(m);
    vector<int> ans(m,0);
    for (int i = 0 ; i < m ; i++)
    {
        cin >> query[i].first;
        query[i].second = i;
    }
    sort(query.begin(),query.end());
    int ptr = 0;
    for (int i = 0 ; i < m ; i++)
    {
        while (ptr < n - 1 && tab[ptr].first <= query[i].first)
        {
            int u = tab[ptr].second.first;
            int v = tab[ptr].second.second;
            joins(u,v);
            ++ptr;
        }
        ans[query[i].second] = cnt;
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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