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

vector< pair<ll,ll> > adj[200010];
ll rata[200010];
ll in[200010];
ll out[200010];
ll sum[200010];
ll tab[200010];
ll tim = 1;

void dfs(ll u,ll curSum)
{
    sum[u] = curSum;
    rata[tim] = curSum - tab[u];
    in[u] = tim++;
    for (auto it : adj[u])
    {
        dfs(it.first,curSum + it.second);
    }
    out[u] = tim - 1;
}

vector<ll> tree[800010];

void build(ll node,ll l,ll r)
{
    if (l == r)
    {
        tree[node].push_back(rata[l]);
        return;
    }
    ll mid = (l + r) >> 1;
    ll child = node << 1;
    build(child,l,mid);
    build(child | 1,mid + 1,r);
    merge(tree[child].begin(),tree[child].end(),tree[child | 1].begin(),tree[child | 1].end(),back_inserter(tree[node]));
}

ll query(ll node,ll nodeL,ll nodeR,ll queryL,ll queryR,ll k)
{
    if (queryL > nodeR || queryR < nodeL) return 0;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        ll ret = upper_bound(tree[node].begin(),tree[node].end(),k) - tree[node].begin();
        return ret;
    }
    ll mid = (nodeL + nodeR) >> 1;
    ll child = node << 1;
    return query(child,nodeL,mid,queryL,queryR,k) + query(child | 1,mid + 1,nodeR,queryL,queryR,k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
        cin >> tab[i];
    for (ll i = 2 ; i <= n ; i++)
    {
        ll a,b;
        cin >> a >> b;
        adj[a].push_back({i,b});
    }
    dfs(1,0);
    // for (ll i = 1 ; i <= n ; i++)
    //     cout << rata[i] << " ";
    // cout << endl;
    build(1,1,n);
    for (ll i = 1 ; i <= n ; i++)
    {
        ll ans = query(1,1,n,in[i] + 1,out[i],sum[i]);
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}