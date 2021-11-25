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

vector<int> adj[200010];
int deg[200010];

void solve()
{
    int n,k;
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        adj[i].clear();
        deg[i] = 0;
    }
    vector<int> them;
    for (int i = 1 ; i <= k ; i++)
    {
        int ta;
        cin >> ta;
        them.push_back(ta);
    }

    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    vector<int> distMe(n + 5,INF),distThem(n + 5,INF);

    const auto bfs = [&](vector<int> source,vector<int> &dist) -> void
    {
        queue<int> q;
        for (auto it : source)
        {
            q.push(it);
            dist[it] = 0;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto it : adj[u]) if (dist[u] + 1 < dist[it])
            {
                dist[it] = dist[u] + 1;
                q.push(it);
            }
        }
    };
    bfs(them,distThem);
    vector<int> me = {1};
    bfs(me,distMe);
    for (int i = 2 ; i <= n ; i++) if (deg[i] == 1 && distMe[i] < distThem[i])
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main()
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