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

int par[30];
int sz[30];

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
    sz[py] += sz[px];
    return 1;
}

void solve()
{
    for (int i = 1 ; i <= 26 ; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    vector< pair<int,int> > edge;
    for (int i = 0 ; i < n ; i++)
    {
        int u = s[i] - 'a' + 1;
        int v = t[i] - 'a' + 1;
        if (joins(u,v))
        {
            edge.push_back({u,v});
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= 26 ; i++) if (finds(i) == i)
    {
        ans += sz[i] - 1;
    }
    cout << ans << endl;
    for (auto it : edge)
        cout << (char)(it.first - 1 + 'a') << " " << (char)(it.second - 1 + 'a') << endl;
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