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

struct dat
{
    int ix;
    int depth;
    bool change_odd;
    bool change_even;
};


vector<int> adj[100010];
bool col[100010];
bool target[100010];
bool vis[100010];
vector<int> ans;

void bfs()
{
    queue< dat > q;
    q.push((dat){1,1,0,0});
    while (!q.empty())
    {
        dat cur = q.front();
        q.pop();
        vis[cur.ix] = 1;
        bool curState = col[cur.ix] ^ (cur.depth % 2 == 0 ? cur.change_even : cur.change_odd);
        if (curState != target[cur.ix])
        {
            ans.push_back(cur.ix);
            if (cur.depth % 2 == 0)
                cur.change_even ^= 1;
            else
                cur.change_odd ^= 1;
        }
        for (auto it : adj[cur.ix]) if (!vis[it])
        {
            q.push((dat){it,cur.depth,cur.change_even,cur.change_odd});
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
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1 ; i <= n ; i++)
        cin >> col[i];
    for (int i = 1 ; i <= n ; i++)
        cin >> target[i];
    bfs();
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << endl;
    return 0;
}