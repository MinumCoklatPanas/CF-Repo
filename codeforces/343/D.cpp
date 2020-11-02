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

struct dt
{
    int val;
    int lazy;

    dt(){};

    dt(int _val,int _lazy)
    {
        val = _val;
        lazy = _lazy;
    }
};


struct segTree
{
    vector<dt> tree;

    segTree(){};

    segTree(int n)
    {
        tree.resize(4 * n + 5,dt(-INF,-INF));
    }

    void combine(int node)
    {
        tree[node].val = max(tree[node * 2].val,tree[node * 2 + 1].val);
    }

    void upd(int node,int v)
    {
        tree[node].val = max(tree[node].val,v);
        tree[node].lazy = max(tree[node].lazy,v);
        return;
    }

    void propagate(int node)
    {
        if (tree[node].lazy == -INF) return;
        upd(node * 2,tree[node].lazy);
        upd(node * 2 + 1,tree[node].lazy);
        tree[node].lazy = -INF;
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
        update(node * 2,nodeL,mid,queryL,queryR,v);
        update(node * 2 + 1,mid + 1,nodeR,queryL,queryR,v);
        combine(node);
    }

    int query(int node,int nodeL,int nodeR,int queryL,int queryR)
    {
        if (queryL > nodeR || queryR < nodeL) return -INF;
        if (queryL <= nodeL && nodeR <= queryR) return tree[node].val;
        propagate(node);
        int mid = (nodeL + nodeR) >> 1;
        return max(query(node * 2,nodeL,mid,queryL,queryR),query(node * 2 + 1,mid + 1,nodeR,queryL,queryR));
    }
};

segTree isi,tarik;

vector<int> adj[500010];
int in[500010];
int out[500010];
int t = 1;

void dfs(int u,int par)
{
    in[u] = t++;
    for (auto it : adj[u]) if (it != par)
        dfs(it,u);
    out[u] = t - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    isi = segTree(n);
    tarik = segTree(n);
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    int q;
    cin >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        int ask,x;
        cin >> ask >> x;
        if (ask == 1)
        {
            isi.update(1,1,n,in[x],out[x],i);
        }
        else
        if (ask == 2)
        {
            tarik.update(1,1,n,in[x],in[x],i);
        }
        else
        {
            int lastIsi = isi.query(1,1,n,in[x],in[x]);
            int lastTarik = tarik.query(1,1,n,in[x],out[x]);
            cout << (lastIsi > lastTarik) << endl;
        }
    }
    
    return 0;
}