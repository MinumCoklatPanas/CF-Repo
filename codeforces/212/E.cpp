#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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

vector<int> adj[5010];
bool can[5010];
int sz[5010];
int par[5010];

int readInt ()
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

bool ada[5010];
int n;
bitset<10010> mark;

void dfs(int u,int prv)
{
    sz[u] = 1;
    par[u] = prv;
    bitset<10010> tmp;
    for (auto it : adj[u]) if (it != prv)
    {
        dfs(it,u);
        sz[u] += sz[it];
    }
    tmp[0] = 1;
    tmp[n - sz[u]] = 1;
    for (auto it : adj[u]) if (it != prv)
    {
        tmp |= (tmp << sz[it]);
    }
    mark |= tmp;
}


int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // cin >> n;
    n = readInt();
    for (int i = 1 ; i < n ; i++)
    {
        int u = readInt(),v = readInt();
        // cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    int cnt = 0;
    for (int i = 1 ; i < n - 1 ; i++)
    {
        if (mark[i] || mark[n - 1 - i])
            ++cnt;
    }
    printf("%d\n",cnt);
    // cout << cnt << endl;
    for (int i = 1 ; i < n - 1; i++)
    {
        if (mark[i] || mark[n - 1 - i])
            printf("%d %d\n",i,n - i - 1);
            // cout << i << " " << n - 1 - i << endl;
    }
    return 0;
}