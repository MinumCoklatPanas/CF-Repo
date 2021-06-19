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


int par[200010];
int sz[200010];

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
    sz[py] += sz[px];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= 200000 ; i++) par[i] = i,sz[i] = 1;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        joins(tab[l],tab[r]);
        ++l; --r;
    } 
    int ans = 0;
    for (int i = 1 ; i <= 200000 ; i++) if (finds(i) == i)
        ans += sz[i] - 1;
    cout << ans << endl;
    return 0;
}