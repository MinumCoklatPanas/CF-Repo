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

int n,m;
vector<int> adj[300010];
vector<int> balik[300010];
int tab[300010];
int dp[30][300010];
int in[300010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        char ta;
        cin >> ta;
        tab[i] = ta - 'a' + 1;
        dp[tab[i]][i] = 1;
    }
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        balik[v].push_back(u);
        in[v]++;
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 1 ; i <= n ; i++) if (in[i] == 0)
        q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for (auto it : adj[cur])
        {
            --in[it];
            if (in[it] == 0)
                q.push(it);
        }
    }
    for (int i = 1 ; i <= n ; i++) if (in[i] != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0 ; i < n ; i++)
    {
        int u = topo[i];
        for (int j = 1 ; j <=  26 ; j++)
        {
            int mx = 0;
            for (auto it : balik[u])
                mx = max(mx,dp[j][it]);
            dp[j][u] += mx;
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        // cout << i << ": ";
        for (int j = 1 ; j <= 26 ; j++)
        {
            // cout << dp[j][i] << " ";
            ans = max(ans,dp[j][i]);
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}