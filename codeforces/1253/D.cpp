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
int mx[200010];

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
    mx[py] = max(mx[py],mx[px]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) par[i] = mx[i] = i;
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        joins(u,v);
    }
    int cur = 1;
    int ans = 0;
    while (cur <= n)
    {
        int curMax = mx[finds(cur)];
        for (int i = cur ; i <= curMax ; i++)
        {
            int px = finds(cur);
            int py = finds(i);
            if (px != py)
            {
                ++ans;
                joins(px,py);
                curMax = mx[finds(cur)];
            }
            // cout << curMax << endl;
            // if (i == 5)
            // return 0;
        }
        cur = curMax + 1;
    }
    cout << ans << endl;
    return 0;
}