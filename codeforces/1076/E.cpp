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

vector<int> adj[300010];
vector< pair<int,int> > qry[300010];
int tree[1200010];
int lazy[1200010];
int n;

void upd(int node,int v)
{
    tree[node] += v;
    lazy[node] += v;
}

void propagate(int node)
{
    upd(node * 2,lazy[node]);
    upd(node * 2 + 1,lazy[node]);
    lazy[node] = 0;
}

void update(int node,int nodeL,int nodeR,int queryL,int queryR,int v)
{
    if (queryL > nodeR || queryR < nodeL) return;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        upd(node,v);
        return;
    }
    propagate(node);
    int mid = (nodeL + nodeR) >> 1;
    int child = node << 1;
    update(child,nodeL,mid,queryL,queryR,v);
    update(child | 1,mid + 1,nodeR,queryL,queryR,v);
}

int get(int node,int l,int r,int ix)
{
    // cout << l << " " << r << " " << node << endl;
    if (l == r) return tree[node];
    propagate(node);
    int mid = (l + r) >> 1;
    int child = node << 1;
    if (ix > mid)
        return get(child | 1,mid + 1,r,ix);
    else
        return get(child,l,mid,ix);
    return 0;
}

int ans[300010];

void dfs(int u,int depth,int prv)
{
    for (auto it : qry[u])
    {
        int l = depth;
        int r = l + it.first;
        update(1,1,n,l,r,it.second);
    }
    // cout << u << " " << depth << endl;
    // cout << "-----------------------------\n";
    // for (int i = 2 ; i <= 2 ; i++)
    //     cout << get(1,1,n,i) << " ";
    // cout << endl;
    // cout << "-----------------------------\n";
    ans[u] = get(1,1,n,depth);
    for (auto it : adj[u]) if (it != prv)
        dfs(it,depth + 1,u);
    for (auto it : qry[u])
    {
        int l = depth;
        int r = l + it.first;
        update(1,1,n,l,r,-it.second);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // update(1,1,n,2,2,10);
    // for (int i = 1 ; i <= n ; i++)
    //     cout << get(1,1,n,i) << " ";
    // cout << endl;
    // return 0;
    int q;
    cin >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        int v,d,x;
        cin >> v >> d >> x;
        qry[v].push_back({d,x});
    }
    dfs(1,1,-1);
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}