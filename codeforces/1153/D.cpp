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

vector<int> adj[300010];
int status[300010];
int dp[300010];
int ans = 1;

void dfs(int u)
{
    if (adj[u].size() == 0)
    {
        dp[u] = 1;
        return;
    }
    if (!status[u])
    {
        for (auto it : adj[u])
        {
            dfs(it);
            dp[u] += dp[it];
        }
    }
    else
    {
        int ret = INF;
        for (auto it : adj[u])
        {
            dfs(it);
            ret = min(ret,dp[it]);
        }
        dp[u] = ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> status[i];
    for (int i = 2 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        adj[ta].push_back(i);
    }
    int leaf = 0;
    for (int i = 2 ; i <= n ; i++) leaf += !(adj[i].size());
    dfs(1);
    int ans = leaf - dp[1] + 1;
    cout << ans << endl;
    return 0;
}