#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int readInt()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = _getchar_nolock();
    while (true)
    {
            if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = _getchar_nolock();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = _getchar_nolock();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

vector< pair<int,int> > adj[100010];
vector< pair<int,int> > t[100010];
int dist[100010];
int n,m;

inline bool valid(pair<int,int> p,int k)
{
    return (p.first <= k && k <= p.second);
}

inline int dijkstra()
{
    for (int i = 2 ; i <= n ; i++) dist[i] = INFF;
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push({0,1});
    while (!pq.empty())
    {
        pair<int,int> cur = pq.top();
        pq.pop();
        int u = cur.second;
        int step = cur.first;
        if (u == n) return step;
        if (dist[u] != step) continue;
        if (t[u].size() > 0 && t[u][0].first <= step && step <= t[u].back().second)
        {
            int l = 0;
            int r = t[u].size() - 1;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (valid(t[u][mid],step)) break;
                if (t[u][mid].first > step)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            int mid = (l + r) >> 1;
            if (valid(t[u][mid],step)) step = t[u][mid].second + 1;
        }
        for (int i = 0 ; i < adj[u].size() ; i++)
        {
            pair<int,int> it = adj[u][i];
            if (step + it.second < dist[it.first])
            {
                dist[it.first] = step + it.second;
                pq.push({step + it.second,it.first});
            }
        }
    }
    return -1;
}

signed main()
{
    n = readInt(); m = readInt();
    for (int i = 1 ; i <= m ; i++)
    {
        int u = readInt(),v = readInt(),w = readInt();
        // cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i = 1 ; i <= n ; i++)
    {
        int k = readInt();
        // cin >> k;
        for (int j = 1 ; j <= k ; j++)
        {
            int ta = readInt();
            // cin >> ta;
            if (t[i].size() == 0)
                t[i].push_back({ta,ta});
            else
            if (t[i].back().second + 1 == ta)
                t[i].back().second++;
            else
                t[i].push_back({ta,ta});
        }
    }
    int ans = dijkstra();
    printf("%d\n",ans);
    return 0;
}