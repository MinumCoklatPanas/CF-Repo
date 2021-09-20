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

int par[100010];

int finds(int x)
{
    return (par[x] == x ? x : par[x] = finds(par[x]));
}

void joins(int x,int y)
{
    int px = finds(x);
    int py = finds(y);
    if (px == py) return;
    par[px] = py;
}

void reset(int n)
{
    for (int i = 1 ; i <= n ; i++) par[i] = i; 
}

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> specials(k);
    for (auto &it : specials) cin >> it;
    vector<pair<pair<int,int>,int>> edges(m);
    for (auto &it : edges) cin >> it.first.first >> it.first.second >> it.second;
    const auto can = [&](int x) -> bool
    {
        reset(n);
        for (auto it : edges) if (it.second <= x)
        {
            joins(it.first.first,it.first.second);
        }
        int papa = finds(specials[0]);
        for (auto it : specials)
        {
            if (finds(it) != papa) return false;
        }
        return true;
    };
    int l = 1;
    int r = INF;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (can(mid))
            r = mid;
        else
            l = mid + 1;
    }
    const auto print = [&](int x) -> void
    {
        for (int i = 1 ; i <= k ; i++) cout << x << " ";
        cout << endl;
    };
    if (can(l))
        print(l);
    else
        print(r);
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