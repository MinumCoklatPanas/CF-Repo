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
const int N = 610;
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

struct MinCostFlow {
  struct Edge {
    int to, cap, flow, rev;
    int cost;
  };
 
  int source = 0, sink = 605;
  vector<Edge> edge[N];
  int pot[N];
 
  void reset() {
    for (int i = 0; i < N; ++i) {
      edge[i].clear();
      pot[i] = 0;
    }
  }
 
  void addEdge(int u, int v, int c, int f) {
    Edge edge1 = {v, f, 0, (int) edge[v].size(), c};
    Edge edge2 = {u, 0, 0, (int) edge[u].size(), -c};
    edge[u].push_back(edge1);
    edge[v].push_back(edge2);
  }
 
  pair<int, int> dijkstra() {
    // pq{cost, flow}
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, source));
 
    vector<bool> vis(sink + 1, false);
    vector<int> dist(sink + 1, INF);
    vector<pair<int, int>> prev(sink + 1);
    
    dist[source] = 0;
    
    while (pq.size()) {
      pair<int, int> now = pq.top();
      int u = now.second;
      pq.pop();
      
      if (vis[u]) continue;
      vis[u] = 1;
      
      for (int i = 0; i < edge[u].size(); ++i) {
        Edge e = edge[u][i];
        int v = e.to;
        
        if (e.cap - e.flow == 0) continue;
        
        int d = dist[u] + e.cost + pot[u] - pot[v];
        if (d < dist[v]) {
          dist[v] = d;
          pq.push(make_pair(-d, v));
          prev[v] = make_pair(u, i);
        }
      }
    }
    
    for (int i = 0; i <= sink; ++i) pot[i] += dist[i];
    
    if (dist[sink] == INF) return make_pair(0, 0);
 
    int f = INF;
    int sum = 0;
    int now = sink;
    
    while (now ^ source) {
      int u = prev[now].first;
      int i = prev[now].second;
      f = min(f, edge[u][i].cap - edge[u][i].flow);
      sum += edge[u][i].cost;
      now = u;
    }
    
    now = sink;
    while (now ^ source) {
      int u = prev[now].first;
      int i = prev[now].second;
      edge[u][i].flow += f;
      edge[now][edge[u][i].rev].flow -= f;
      now = u;
    }
    
    return make_pair(f, sum * f);
  };
  
  // {flow, cost}
  pair<int, int> minCostMaxFlow() {
    pair<int, int> tmp = dijkstra();
    pair<int, int> ret = make_pair(0, 0);
    while (tmp.first) {
      ret.first += tmp.first;
      ret.second += tmp.second;
      tmp = dijkstra();
    }
    return ret;
  }
};

void solve()
{
    int n;
    cin >> n;
    MinCostFlow mcmf;
    mcmf.reset();
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        mcmf.addEdge(mcmf.source,i,0,1);
        for (int j = 1 ; j <= 400 ; j++)
        {
            int cost = abs(ta - j);
            mcmf.addEdge(i,n + j,cost,INF);
        }
    }
    for (int i = 1 ; i <= 400 ; i++) mcmf.addEdge(i + n,mcmf.sink,0,1);
    int ans = mcmf.minCostMaxFlow().second;
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