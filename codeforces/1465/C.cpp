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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> deg(n,0);
    vector<vector<int>> adj(n);
    for (int i = 0 ; i < m ; i++)
    {
        int x,y;
        cin >> x >> y;
        --x; --y;
        if (x == y) continue;
        adj[x].push_back(y);
        deg[y]++;
    }
    int ans = 0;
    queue<int> q;
    for (int i = 0 ; i < n ; i++) if (deg[i] == 0 && adj[i].size() != 0)
        q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        // cerr << cur << endl;
        q.pop();
        if (adj[cur].size() > 0)
        {
            ++ans;
            --deg[adj[cur][0]];
            if (deg[adj[cur][0]] == 0)
                q.push(adj[cur][0]);
        }
    }
    for (int i = 0 ; i < n ; i++) if (deg[i])
    {
        int cnt = 0;
        int cur = i;
        do
        {
            ++cnt;
            deg[cur] = 0;
            cur = adj[cur][0];
        } while (cur != i);
        ans += cnt + 1;
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