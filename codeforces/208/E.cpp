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

vector<int> adj[100010];
int depth[100010];
int in[100010];
int out[100010];
int rata[100010];
int spa[20][100010];
int grandpa[100010];
map<int,int> tree[400010];
int tim = 1;
int n;


void dfs(int u,int prv,int root)
{
    grandpa[u] = root;
    in[u] = tim;
    rata[tim++] = u;
    for (auto it : adj[u]) if (it != prv)
    {
        spa[0][it] = u;
        depth[it] = depth[u] + 1;
        dfs(it,u,root);
    }
    out[u] = tim - 1;
}

void build(vector<int> &roots)
{
    memset(spa,-1,sizeof(spa));
    for (auto it : roots)
    {
        depth[it] = 1;
        dfs(it,-1,it);
    }
    for (int i = 1 ; i < 20 ; i++)
        for (int j = 1 ; j <= n ; j++) if (spa[i - 1][j] != -1)
        {

            spa[i][j] = spa[i - 1][spa[i - 1][j]];
        }
}

void build(int node,int l,int r,int v)
{
    tree[node][depth[rata[v]]]++;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    int child = node << 1;
    if (v <= mid)
        build(child,l,mid,v);
    else
        build(child | 1,mid + 1,r,v);
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR,int v)
{
    if (queryL > nodeR || queryR < nodeL) return 0;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        if (!tree[node].count(v)) return 0;
        else return tree[node][v];
    }
    int mid = (nodeL + nodeR) >> 1;
    int child = node << 1;
    return query(child,nodeL,mid,queryL,queryR,v) + query(child | 1,mid + 1,nodeR,queryL,queryR,v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int n;
    cin >> n;
    vector<int> roots;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta == 0)
            roots.push_back(i);
        else
        {
            adj[ta].push_back(i);
            adj[i].push_back(ta);
        }
    }
    build(roots);
    // for (int i = 1 ; i <= n ; i++)
    //     cout << depth[rata[i]] << " ";
    // cout << endl;
    for (int i = 1 ; i <= n ; i++)
        build(1,1,n,i);
    // if (n == 100000)
    //     cout << in[1] << " " << out[1] << endl;
    // cout << query(1,1,n,1,3,2) << endl;
    // return 0;
    int q;
    cin >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        int a,b;
        cin >> a >> b;
        // if (n == 100000)
        // {
        //     cout << a << " " << b << endl;
        //     return 0;
        // }
        if (depth[a] <= b)
        {
            cout << 0;
        }
        else
        {
            int depthAwal = depth[a];
            const auto naik = [&]() -> int
            {
                for (int j = 0 ; j < 19 ; j++) if (b & (1 << j))
                {
                    a = spa[j][a];
                }
                return a;
            };
            naik();
            int l = in[a];
            int r = out[a];
            int ans = query(1,1,n,l,r,depthAwal) - 1;
            cout << ans;
        }
        if (i == q)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}