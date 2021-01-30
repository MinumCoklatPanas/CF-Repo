#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

int n,m,k;
vector<int> adj[100010];
int label[100010];
int dist[20][100010];
int distSpecial[20][20];

void bfs(int from)
{
    for (int i = 1 ; i <= n ; i++) dist[label[from]][i] = INF;
    dist[label[from]][from] = 0;
    queue< int > q;
    q.push(from);
    while (!q.empty())
    {
        int cur = q.front();
        // cout << cur << endl;
        q.pop();
        for (auto it : adj[cur]) if (dist[label[from]][it] > dist[label[from]][cur] + 1)
        {   
            dist[label[from]][it] = dist[label[from]][cur] + 1;
            q.push(it);
        }
    }
    for (int i = 1 ; i <= n ; i++) if (label[i] != -1)
        distSpecial[label[from]][label[i]] = dist[label[from]][i];
}

int dp[200010][20];
vector<int> transition[200010];

int rec(int mask,int last)
{
    // cout << mask << " " << last << endl;
    if (__builtin_popcount(mask) == k) return 0;
    if (dp[mask][last] != -1) return dp[mask][last];
    int ret = INF;
    for (auto i : transition[mask]) if (distSpecial[last][i] != INF)
    {
        ret = min(ret,distSpecial[last][i] - 1 + rec(mask | (1 <<i),i));
    }
    return dp[mask][last] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    memset(label,-1,sizeof(label));
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // int k;
    cin >> k;
    vector<int> special;
    for (int i = 0 ; i < k ; i++)
    {
        int ta;
        cin >> ta;
        label[ta] = i;
        special.push_back(ta);
    }
    for (auto it : special)
    {
        bfs(it);
    }
    for (int i = 0 ; i < (1 << k) ; i++)
    {
        for (int j = 0 ; j < k ; j++) if (!((1 << j) & i))
            transition[i].push_back(j);
    }
    // for (int i = 0 ; i < k ; i++)
    // {
    //     for (int j = 0 ; j < k ; j++)
    //     {
    //         cerr << distSpecial[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    int len = INF;
    for (auto it : special)
    {
        len = min(len,rec(1 << label[it],label[it]));
        // return 0;
    }
    // cout << len << endl;
    if (len == INF) cout << -1 << endl;
    else cout << len + k << endl;
    return 0;
}