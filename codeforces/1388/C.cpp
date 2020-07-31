#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

vector<ll> adj[100010];
ll tab[100010];
ll target[100010];
ll happy[100010];
ll sad[100010];
ll sub[100010];

void dfs2(ll node,ll prv)
{
    sub[node] += tab[node];
    for (auto it : adj[node]) if (it != prv)
    {
        dfs2(it,node);
        sub[node] += sub[it];
    }
    // cout << node << ": " << sub[node] << endl;
}

bool dfs(ll node,ll prv)
{
    // cout << "yo\n";
    // cout << node << endl;
    ll x = sub[node] + target[node];
    ll y = sub[node] - target[node];
    // cout << node << ": " << x << " " << y << " " << sub[node] << endl;
    if (x % 2 != 0) return false;
    if (y % 2 != 0) return false;
    if (x < 0) return false;
    if (y < 0) return false;
    happy[node] = x / 2;
    sad[node] = y / 2;
    bool ret = 1;
    ll h = 0;
    ll s = 0;
    for (auto it : adj[node]) if (it != prv)
    {
        ret &= dfs(it,node);
        h += happy[it];
        s += sad[it];
        // cout << it << " " << node << " " << happy[it] << " " << sad[it] << endl;
    }
    // cout << node << ": " << happy[node] << " " << sad[node] << " " << h << " " << s << endl;
    if (h > happy[node]) return false;
    if (h + s > happy[node] + sad[node]) return false;
    return ret;
}

void solve()
{
    ll n,m;
    cin >> n >> m;
    for (ll i = 1 ; i <= n ; i++)
    {
        adj[i].clear();
        sub[i] = happy[i] = sad[i] = 0;
    }
    for (ll i = 1 ; i <= n ; i++)
        cin >> tab[i];
    for (ll i = 1 ; i <= n ; i++)
        cin >> target[i];
    for (ll i = 1 ; i < n ; i++)
    {
        ll u,v;
        cin >> u >> v;
        // cout << u << " " << v << endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs2(1,-1);
    if (dfs(1,-1))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
