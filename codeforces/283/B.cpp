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

vector<int> adj[400010];
int deg[400010];
int tab[400010];
bool isInCycle[400010];
int dp[400010];
int n;

int rec(int u,bool visited)
{
    int normal = u / 2;
    if (normal == 1 && visited) return -INFF;
    if (isInCycle[u]) return -INFF;
    if (dp[u] != -1) return dp[u];
    int ret = tab[normal];
    //ke kanan
    if (u % 2 == 0)
    {
        int nxt = normal + tab[normal];
        if (nxt <= n)
            ret += rec(2 * nxt + 1,1);
    }
    else
    //ke kiri
    {
        int nxt = normal - tab[normal];
        if (nxt > 0)
            ret += rec(2 * nxt,1);
    }
    return dp[u] = ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    const auto leftVertex = [&](int x) -> int {return 2 * x + 1;};
    const auto rightVertex = [&](int x) -> int {return 2 * x;};
    const auto makeEdge = [&](int x,int y) -> void
    {
        adj[x].push_back(y);
        deg[y]++;
    };
    for (int i = 2 ; i <= n ; i++)
    {
        cin >> tab[i];
        int vertexKeKanan = rightVertex(i);
        int vertexKeKiri = leftVertex(i);
        if (i + tab[i] <= n)
        {
            int nxt = i + tab[i];
            makeEdge(vertexKeKanan,leftVertex(nxt));
        }
        if (i - tab[i] >= 2)
        {
            int nxt = i - tab[i];
            makeEdge(vertexKeKiri,rightVertex(nxt));
        }
    }
    queue<int> q;
    for (int i = 4 ; i <= 2 * n + 1 ; i++) if (deg[i] == 0)
        q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : adj[cur])
        {
            --deg[it];
            if (deg[it] == 0)
                q.push(it);
        }
    }
    for (int i = 4 ; i <= 2 * n + 1 ; i++) if (deg[i] == 1) isInCycle[i] = 1;
    memset(dp,-1,sizeof(dp));
    for (int i = 1 ; i < n ; i++)
    {
        tab[1] = i;
        dp[2] = -1;
        int ans = max(-1ll,rec(2,0));
        cout << ans << endl;
    }
    return 0;
}