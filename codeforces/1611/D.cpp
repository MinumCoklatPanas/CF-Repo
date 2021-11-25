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

vector<int> child[200010];
int par[200010];
int pos[200010];
int dp[200010];
int order[200010];
int ans[200010];
bool can = 1;

void dfs(int u,int curMax)
{
    if (curMax > pos[u])
    {
        // cerr << u << endl;
        can = 0;
        return;
    }
    curMax = max(curMax,pos[u]);
    for (auto it : child[u])
        dfs(it,curMax);
}

void solve()
{
    can = 1;
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) child[i].clear(),dp[i] = 0,ans[i] = 0;
    int root = -1;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> par[i];
        if (i == par[i])
        {
            root = i;
        }
        else
        {
            child[par[i]].push_back(i);
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        pos[ta] = i;
        order[i] = ta;
    }
    dfs(root,-1);
    if (!can)
        cout << -1 << endl;
    else
    {
        int cur = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            ans[order[i]] = cur - dp[par[order[i]]];
            dp[order[i]] = dp[par[order[i]]] + ans[order[i]];
            ++cur;
        }
        for (int i = 1 ; i <= n ; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
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