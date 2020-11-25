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
#define int long long

int n;
vector<int> adj[200010];
int deg[200010];
bool dah[200010];
int sum[200010];

void solve()
{
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        adj[i].clear();
        deg[i] = 0;
        dah[i] = 0;
        sum[i] = 1;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue< int > q;
    for (int i = 1 ; i <= n ; i++) if (deg[i] == 1)
        q.push(i), dah[i] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : adj[cur]) if (!dah[it])
        {
            --deg[it];
            sum[it] += sum[cur];
            if (deg[it] == 1)
            {
                q.push(it);
                dah[it] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) if (deg[i] > 1)
    {
        // cout << sum[i] << " ";
        ans += (sum[i] * (sum[i] - 1)) / 2;
        ans += (sum[i]) * (n - sum[i]);
    }
    // cout << endl;
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}