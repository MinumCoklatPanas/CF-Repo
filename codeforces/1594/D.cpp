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

vector<pair<int,int>> adj[200010];
int col[200010];
int indeg[200010];
bool cons = 0;
int cnt0 = 0,cnt1 = 0;

//0 crew 1 impostor

void dfs(int u,int c)
{
    // cerr << u << " " << c << endl;
    col[u] = c;
    if (c == 0)
        cnt0++;
    else
        cnt1++;
    for (auto it : adj[u])
    {
        int v = it.first;
        int role = it.second;
        if (col[v] == -1)
        {   
            dfs(v,col[u] ^ role);
        }
        else
        {
            int roleAsli = col[v];
            int says = col[u] ^ role;
            if (roleAsli != says)
            {
                cons = 1;
            }
        }
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;
    cons = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        col[i] = -1;
        adj[i].clear();
        indeg[i] = 0;
    }
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        string s;
        cin >> u >> v >> s;
        adj[u].push_back({v,(s == "imposter")});
        adj[v].push_back({u,(s == "imposter")});
        indeg[v]++;
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) if (col[i] == -1)
    {
        cnt0 = 0,cnt1 = 0;
        dfs(i,0);
        ans += max(cnt0,cnt1);
    }
    if (cons)
        cout << -1 << endl;
    else
    {
        cout << ans << endl;
    }
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