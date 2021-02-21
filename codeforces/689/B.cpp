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
int dist[200010];

void bfs()
{
    queue< pair<int,int> > q;
    q.push({0,1});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int u = cur.second;
        int step = cur.first;
        for (auto it : adj[u]) if (dist[it] > step + 1)
        {
            dist[it] = step + 1;
            q.push({step + 1,it});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta != i)
            adj[i].push_back(ta);
        if (i != n)
            adj[i].push_back(i + 1);
        if (i != 1)
            adj[i].push_back(i - 1);
        dist[i] = INF;
    }
    dist[1] = 0;
    bfs();
    for (int i = 1 ; i <= n ; i++)
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}