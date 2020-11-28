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
#define int long long

vector<int> adj[200010];
int tab[200010];
int subtreeSum[200010];
int ans = 0;
int tot = 0;
int allSum = 0;

void dfs(int u, int prv, int depth)
{
    tot += tab[u] * depth;
    subtreeSum[u] = tab[u];
    for (auto it : adj[u]) if (it != prv)
    {
        dfs(it, u, depth + 1);
        subtreeSum[u] += subtreeSum[it];
    }
}

void dfs2(int u, int prv, int curSum)
{
    // cout << u << " " << curSum << endl;
    ans = max(ans, curSum);
    for (auto it : adj[u]) if (it != prv)
    {
        int newSum = curSum;
        newSum -= subtreeSum[it];
        newSum += (allSum - subtreeSum[it]);
        dfs2(it, u, newSum);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i], allSum += tab[i];
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0);
    dfs2(1,0,tot);
    cout << ans << endl;
    return 0;
}