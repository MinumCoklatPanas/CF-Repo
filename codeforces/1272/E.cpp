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
int ans[200010];
int tab[200010];
int n;

void bfs(vector<int> vertex, int parity)
{
    vector<int> dist(n + 5, INF);
    queue< pair<int,int> > q;
    for (auto it : vertex)
    {
        q.push({it,0});
        dist[it] = 0;
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int u = cur.first;
        int step = cur.second;
        for (auto it : adj[u]) if (dist[it] > step + 1)
        {
            dist[it] = step + 1;
            q.push({it, step + 1});
        }
    }
    // for (int i = 1 ; i <= n ; i++)
    //     cout << dist[i] << " ";
    // cout << endl;
    for (int i = 1 ; i <= n ; i++) if (tab[i] % 2 == (parity ^ 1))
        ans[i] = dist[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(ans, -1, sizeof(ans));
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (1 <= i - ta)
            adj[i - ta].push_back(i);
        if (i + ta <= n)
            adj[i + ta].push_back(i);
        tab[i] = ta;
    }
    vector<int> vertex;
    for (int i = 1 ; i <= n ; i++) if (tab[i] % 2 == 0) vertex.push_back(i);
    bfs(vertex,0);
    // return 0;
    vertex.clear();
    for (int i = 1 ; i <= n ; i++) if (tab[i] % 2 == 1) vertex.push_back(i);
    bfs(vertex,1);
    for (int i = 1 ; i <= n ; i++)
    {
        if (ans[i] == INF) ans[i] = -1;
        cout << ans[i] << " ";
    }
    cout << endl; 
    return 0;
}