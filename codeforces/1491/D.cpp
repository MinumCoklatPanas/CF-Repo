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
#define MULTI_TC 1

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

bool found = 0;
map<int,bool> vis;
void dfs(int u,int v)
{
    // cout << u << " " << v << endl;
    if (u > v) return;
    if (vis[u]) return;
    if (u == v)
    {
        found = 1;
        return;
    }
    if ((u % 2 == 0) && (v % 2 == 1)) return;
    vis[u] = 1;
    int ctzU = __builtin_ctz(u);
    int ctzV = __builtin_ctz(v);
    if (ctzV < ctzU) return;
    for (int i = 0 ; i < 30 ; i++) if (u & (1 << i))
    {
        dfs(u + (1 << i),v);
        if (found) break;
    }

}

void solve()
{
    // for (int i = 1 ; i <= 100 ; i++)
    //     for (int j = i ; j <= 100 ; j++)
    //     {
    //         int rem = j - i;
    //         if ((i & rem) == rem)
    //             cout << i << " " << j  << endl;
    //     }
    int u,v;
    cin >> u >> v;
    if (u > v)
        cout << "NO\n";
    else
    {
        while (u > 0 && v > 0)
        {
            int ctzU = __builtin_ctz(u);
            int ctzV = __builtin_ctz(v);
            if (ctzV < ctzU)
            {
                cout << "NO\n";
                return;
            }
            u ^= (1 << ctzU);
            v ^= (1 << ctzV);
        }
        if (v == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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