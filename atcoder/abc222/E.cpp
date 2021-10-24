#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353;
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

vector<int> adj[1010];
int par[1010];
int cnt[1010];
int depth[1010];

void dfs(int u)
{
    for (auto it : adj[u]) if (it != par[u])
    {
        depth[it] = depth[u] + 1;
        par[it] = u;
        dfs(it);
    }
}

void walk(int u,int v)
{
    if (depth[u] < depth[v]) swap(u,v);
    while (depth[u] > depth[v])
    {
        ++cnt[u];
        u = par[u];
    }
    while (u != v)
    {
        ++cnt[u]; ++cnt[v];
        u = par[u]; v = par[v];
    }
    return;
}

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int sub(int x,int y)
{
    int ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0) ret += MOD;
    return ret;
}

int mul(int x,int y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

int modpow(int x,int y)
{
    if (!y) return 1;
    int z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

int reverse(int x)
{
    return modpow(x,MOD - 2);
}

int bagi (int x,int y)
{
    return mul(x,reverse(y));
}

int n,m,k,tot;
int dp[1010][100010];
int tab[1010];
vector<int> nums;

int rec(int ix,int cntRed)
{
    if (ix == nums.size())
    {
        int cntBlue = tot - cntRed;
        return (cntRed - cntBlue == k);
    }
    if (dp[ix][cntRed] != -1) return dp[ix][cntRed];
    int ans = 0;
    ans = rec(ix + 1,cntRed);
    ans = add(ans,rec(ix + 1,cntRed + nums[ix]));
    // cerr << ix << " " << cntRed << " " << ans << endl;
    return dp[ix][cntRed] = ans;
}

void solve()
{   
    cin >> n >> m >> k;
    for (int i = 1 ; i <= m ; i++) cin >> tab[i];
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 2 ; i <= m ; i++)
        walk(tab[i],tab[i - 1]);
    int ans = 1;
    for (int i = 2 ; i <= n ; i++)
    { 
        tot += cnt[i];
        if (cnt[i]) nums.push_back(cnt[i]);
        else ans = mul(ans,2);
    }
    memset(dp,-1,sizeof(dp));
    ans = mul(ans,rec(0,0));
    // ans = bagi(ans,2ll);
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