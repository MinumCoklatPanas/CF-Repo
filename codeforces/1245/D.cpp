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

int par[2010];

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

vector< pair<int,int> > adj[2010];
int papa[2010];
int distToPapa[2010];

void dfs(int u,int prv)
{
    for (auto it : adj[u]) if (it.first != prv)
    {
        papa[it.first] = u;
        distToPapa[it.first] = it.second;
        dfs(it.first,u);
    }
}

vector< pair<int,int> > used;
int sambung[2010];

void dfs2(int u)
{
    // cerr << u << endl;
    for (auto it : adj[u]) if (it.first != papa[u] && sambung[it.first])
    {
        used.push_back({u,it.first});
        dfs2(it.first);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(papa,-1,sizeof(papa));
    int n;
    cin >> n;
    for (int i = 0 ; i <= n ; i++) par[i] = i;
    vector< pair<int,int> > tab(n);
    vector< int > c(n);
    vector< int > k(n);
    for (auto &it : tab) cin >> it.first >> it.second;
    for (auto &it : c) cin >> it;
    for (auto &it : k) cin >> it;
    vector< pair<int,pair<int,int>> > edge;

    const auto dist = [&](pair<int,int> a,pair<int,int> b) -> int
    {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    int ans = 0;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = i + 1 ; j < n ; j++)
        {
            int cost = dist(tab[i],tab[j]) * (k[i] + k[j]);
            edge.push_back({cost,{i,j}});
        }
        edge.push_back({c[i],{i,n}});
    }

    sort(edge.begin(),edge.end());
    vector<int> roots;
    vector< pair<int,int> > used;
    for (auto it : edge) 
    {
        int cost = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (joins(u,v))
        {
            if (v != n)
                used.push_back(it.second);
            else
                roots.push_back(u);
            ans += cost;
        }
    }
    cout << ans << endl;
    cout << roots.size() << endl;
    for (auto it : roots)
        cout << it + 1 << " ";
    cout << endl;
    cout << used.size() << endl;
    for (auto it : used)
        cout << it.first + 1 << " " << it.second + 1 << endl;
    return 0;
}