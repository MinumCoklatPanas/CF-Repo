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

vector<int> adj[200010];
int in[200010];
int out[200010];
int depth[200010];
int num = 1;

void dfs(int u,int prv,int deep)
{
    in[u] = num++;
    depth[u] = deep;
    for (auto it : adj[u]) if (it != prv)
        dfs(it,u,deep + 1);
    out[u] = num - 1;
}

int tree[800010];
int lazy[2][800010];
int tab[200010];

void upd(int segNode,int depthNode,int val)
{
    lazy[depthNode % 2][segNode] += val;
    lazy[(depthNode % 2) ^ 1][segNode] -= val;
    // cout << lazy[0][segNode] << " " << lazy[1][segNode] << endl;
    return;
}

void propagate(int segNode)
{
    int child = segNode << 1;
    lazy[0][child] += lazy[0][segNode];
    lazy[1][child] += lazy[1][segNode];
    lazy[0][child | 1] += lazy[0][segNode];
    lazy[1][child | 1] += lazy[1][segNode];
    lazy[0][segNode] = lazy[1][segNode] = 0;
    return;
}

void rangeUpdate(int segNode,int nodeL,int nodeR,int queryL,int queryR,int depthNode,int val)
{
    if (queryL > nodeR || queryR < nodeL) return;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        // cout << segNode << ": " << nodeL << " " << nodeR << endl;
        upd(segNode,depthNode,val);
        return;
    }
    propagate(segNode);
    int child = segNode << 1;
    int mid = (nodeL + nodeR) >> 1;
    rangeUpdate(child,nodeL,mid,queryL,queryR,depthNode,val);
    rangeUpdate(child | 1,mid + 1,nodeR,queryL,queryR,depthNode,val);
}

int get(int node,int l,int r,int ix,int treeNode)
{
    if (l == r)
    {
        // cout << lazy[0][node]
        return lazy[depth[treeNode] % 2][node] + tab[treeNode];
    }
    propagate(node);
    int mid = (l + r) >> 1;
    int child = node << 1;
    if (ix <= mid)
        return get(child,l,mid,ix,treeNode);
    else
        return get(child | 1,mid + 1,r,ix,treeNode);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i];
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1,1);
    while (q--)
    {
        int ask;
        cin >> ask;
        if (ask == 1)
        {
            int x,val;
            cin >> x >> val;
            // cout << in[x] << " " << out[x] << endl;
            // cout << depth[x] << endl;
            rangeUpdate(1,1,n,in[x],out[x],depth[x],val);
            // cout << "===================================================\n";
            // for (int i = 1 ; i <= n ; i++)
            //     cout << i << ": " << get(1,1,n,in[i],i) << "\n";
            // cout << endl;
        }
        else
        {
            // cout << "yo\n";
            int x;
            cin >> x;
            cout << get(1,1,n,in[x],x) << endl;
        }
    }
    return 0;
}