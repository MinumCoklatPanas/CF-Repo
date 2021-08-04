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
#define MULTI_TC 0

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

vector<int> adj[50010];
int cnt[50010][510];
int par[50010];
int n,k;

void dfs(int u)
{
    for (auto it : adj[u]) if (it != par[u])
    {
        par[it] = u;
        dfs(it);
    }
}

void naik(int x)
{
    cnt[x][0] = 1;
    for (int i = 1 ; i <= k && x != 0 ; i++)
    {
        cnt[par[x]][i]++;
        x = par[x];
    }
}

int ans;

void calc(int x)
{
    int tmp = 0;
    ans += cnt[x][k];
    tmp += cnt[x][k];
    for (int i = 1 ; i <= k && par[x] != 0 ; i++)
    {
        int papa = par[x];
        int rem = k - i;
        int included = cnt[papa][rem] - cnt[x][rem - 1];
        ans += included;
        tmp += included;
        x = par[x];
    }
    // cerr << x << " " << tmp << " " << cnt[x][k] << endl;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1 ; i <= n ; i++)
        naik(i);
    for (int i = 1 ; i <= n ; i++)
        calc(i);
    cout << ans / 2 << endl;
    
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