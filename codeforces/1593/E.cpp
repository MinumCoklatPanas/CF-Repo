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
    int n,k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 5);
    vector<int> deg(n + 5,0);
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    set<int> st;
    for (int i = 1 ; i <= n ; i++) st.insert(i);
    queue<pair<int,int>> q;
    for (int i = 1 ; i <= n ; i++) if (deg[i] == 1)
        q.push({i,1});
    // cerr << q.size() << endl;
    // return;
    for (int i = 1 ; i <= k && st.size() > 0 ; i++)
    {
        while (!q.empty() && q.front().second == i)
        {
            auto cur = q.front();
            q.pop();
            int u = cur.first;
            int step = cur.second;
            // cerr << u << " " << step << endl;
            --deg[u];
            st.erase(u);
            for (auto it : adj[u])
            {
                --deg[it];
                if (deg[it] == 1)
                {
                    q.push({it,step + 1});
                }
            }
        }
    }
    cout << st.size() << endl;
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