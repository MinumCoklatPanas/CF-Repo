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

int tab[200010];
vector<int> adj[200010];
bool vis[200010];

int rec(int u)
{
    if (vis[u]) return 0;
    vis[u] = 1;
    int res = tab[u];
    for (auto it : adj[u]) res += rec(it);
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int k;
        cin >> tab[i] >> k;
        for (int j = 1 ; j <= k ; j++)
        {
            int u;
            cin >> u;
            adj[i].push_back(u);
        }
    }
    int res = rec(n);
    cout << res << endl;
    return 0;
}