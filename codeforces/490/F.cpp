#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int readInt()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = _getchar_nolock();
    while (true)
    {
            if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = _getchar_nolock();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = _getchar_nolock();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

inline int MAX(int a,int b) {return (a > b ? a : b);}

int tab[6010];
vector<int> adj[6010];
int segTree[24010];
int frek[6010];
int ans,n = 0,ix = 1;

void upd(int ix,int val)
{
    for (segTree[ix += n] = val ; ix > 1 ; ix >>= 1) segTree[ix >> 1] = max(segTree[ix], segTree[ix ^ 1]);
}

int query(int l,int r)
{
    int ret = 0;
    for (l += n, r += n ; l < r ; l >>= 1, r >>= 1)
    {
        if (l & 1) ret = max(ret,segTree[l++]);
        if (r & 1) ret = max(ret,segTree[--r]);
    }
    return ret;
}

void dfs(int &node,int par)
{
    int LIS = query(1,tab[node]) + 1;
    int oldVal = frek[tab[node]];
    frek[tab[node]] = LIS;
    upd(tab[node],LIS);
    ans = MAX(ans,LIS);
    for (auto it : adj[node]) if (it != par)
    {
        dfs(it,node);
    }
    frek[tab[node]] = oldVal;
    upd(tab[node],oldVal);
}

gp_hash_table<int,int> mp;

int main()
{
    n = readInt();
    // cin >> n;
    vector<int> st;
    for (int i = 1 ; i <= n ; i++) tab[i] = readInt(), st.push_back(tab[i]);
    for (int i = 1 ; i < n ; i++)
    {
        int u = readInt(),v = readInt();
        // cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(st.begin(),st.end());
    st.erase(unique(st.begin(),st.end()),st.end());
    ix = 1;
    for (auto it : st)
        mp[it] = ix++;
    for (int i = 1 ; i <= n ; i++) tab[i] = mp[tab[i]];
    for (int i = 1 ; i <= n ; i++)
    {
        dfs(i,-1);
    }
    printf("%d\n",ans);
    return 0;
}