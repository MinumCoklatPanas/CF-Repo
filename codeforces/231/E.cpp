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
const int LOG = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector< pair<ll,ll> > Graph_adj[100010];
ll parent[100010];
ll dfs_num[100010];
ll dfs_low[100010];
ll num = 1;
bool vis[100010];
int cntElement[100010];
vector<int> elements[100010];
map< pair<ll,ll>,bool > mp;
ll cntBridge;

void dfs(ll u,ll prv)
{
	for (ll i = 0 ; i < Graph_adj[u].size() ; i++) if (Graph_adj[u][i].first != prv)
		dfs(Graph_adj[u][i].first,u);
}

//cari bridge
void FindBridge(ll u)
{
	dfs_num[u]=dfs_low[u]=num++;
	vis[u]=1;
	for (ll i=0;i<Graph_adj[u].size();i++)
	{
		if (!vis[Graph_adj[u][i].first])
		{
			parent[Graph_adj[u][i].first]=u;
			FindBridge(Graph_adj[u][i].first);
			dfs_low[u]=min(dfs_low[u],dfs_low[Graph_adj[u][i].first]);
			if (dfs_low[Graph_adj[u][i].first] > dfs_num[u])
			{	
				mp[make_pair(u,Graph_adj[u][i].first)] = mp[make_pair(Graph_adj[u][i].first,u)] = 1;
				++cntBridge;
			}
			
		}
		else
		 if (parent[u]!=Graph_adj[u][i].first)
		  dfs_low[u]=min(dfs_low[u],dfs_num[Graph_adj[u][i].first]);
	}
	return;
}

void FindBridge()
{
	memset(vis,0,sizeof(vis));
	cntBridge = 0;
	FindBridge(1);
}

//bikin Bridge-tree
vector< pair<ll,ll> > Tree_adj[100010];
queue<ll> q[100010];
ll ConnectedComponent;
ll n,m;
ll prov[100010];

void MakeBridgeTree(ll u)
{
	ll currcmp = ConnectedComponent;
	q[currcmp].push(u);
	vis[u] = 1;
	while (!q[currcmp].empty())
	{
		ll v = q[currcmp].front();
		q[currcmp].pop();
		prov[v] = currcmp;
        cntElement[currcmp]++;
        elements[currcmp].push_back(v);
		for (ll i = 0 ; i < Graph_adj[v].size() ; i++)
		{
			if (vis[Graph_adj[v][i].first]) continue;
			if (mp[make_pair(v,Graph_adj[v][i].first)])
			{
				++ConnectedComponent;
				Tree_adj[currcmp].push_back({ConnectedComponent,Graph_adj[v][i].second});
				Tree_adj[ConnectedComponent].push_back({currcmp,Graph_adj[v][i].second});
				MakeBridgeTree(Graph_adj[v][i].first);
			}
			else
			{
				q[currcmp].push(Graph_adj[v][i].first);
				vis[Graph_adj[v][i].first] = 1;
			}
		}
	}
}

void BuildBridgeTree()
{
	ConnectedComponent = 1;
	memset(vis,0,sizeof(vis));
	MakeBridgeTree(1);
	assert(ConnectedComponent == cntBridge + 1);
}

int sum[100010];
int spa[22][100010];
int depth[100010];

void dfs2(int u,int prv)
{
    for (auto it : Tree_adj[u]) if (it.first != prv)
    {
        spa[0][it.first] = u;
        depth[it.first] = depth[u] + 1;
        sum[it.first] = sum[u] + (cntElement[it.first] > 1);
        dfs2(it.first,u);
    }
}

void buildSparse()
{
    memset(spa,-1,sizeof(spa));
    sum[1] = cntElement[1] > 1;
    dfs2(1,0);
    for (int i = 1 ; i <= LOG ; i++)
        for (int j = 1 ; j <= ConnectedComponent ; j++) if (spa[i - 1][j] != -1)
            spa[i][j] = spa[i - 1][spa[i - 1][j]];
}

int getLCA(int u,int v)
{
    if (depth[u] < depth[v]) swap(u,v);
    for (int i = LOG ; i >= 0 ; i--) if (depth[u] - (1 << i) >= depth[v])
    {
        u = spa[i][u];
    }
    if (u == v) return v;
    for (int i = LOG  ; i >= 0 ; i--) if (spa[i][u] != spa[i][v] && spa[i][u] != -1)
    {
        u = spa[i][u];
        v = spa[i][v];
    }
    return spa[0][u];
}

int mul(int x,int y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int sub(int x,int y)
{
    int ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0)
        ret += MOD;
    return ret;
}

int modpow(int x,int y)
{
    if (!y) return 1;
    int z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

int inv(int x)
{
    return modpow(x,MOD - 2);
}

int bagi(int x,int y)
{
    return mul(x,inv(y));
}

int query(int u,int v)
{
    u = prov[u];
    v = prov[v];
    if (depth[u] < depth[v]) swap(u,v);
    int lca = getLCA(u,v);
    if (lca == v)
    {
        if (v == 1) return sum[u];
        else return sum[u] - sum[spa[0][v]];
    }
    // cout << lca << endl;
    // cout << u << " " << v << endl;
    // return 0;
    int cnt = sum[u] + sum[v] - sum[lca];
    if (lca != 1)
        cnt -= sum[spa[0][lca]];
    // cout << cnt << endl;
    return cnt;
}

void PreProcess()
{
	FindBridge();
	BuildBridgeTree();
	buildSparse();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        Graph_adj[u].push_back({v,0});
        Graph_adj[v].push_back({u,0});
    }
    PreProcess();
    // cout << ConnectedComponent << endl;
    // for (int i = 1 ; i <= ConnectedComponent ; i++)
    // {
    //     cout << i << ": ";
    //     for (auto it : Tree_adj[i])
    //         cout << it.first << " ";
    //     cout << sum[i] << " ";
    //     cout << endl;
    // }
    // cout << modpow(2ll,query(13,11)) << endl;
    // return 0;
    // cout << "yo\n";
    // return 0;
    int q;
    cin >> q;
    while (q--)
    {
        int u,v;
        cin >> u >> v;
        int cnt = query(u,v);
        int ans = modpow(2ll,cnt);
        cout << ans << endl;
    }
    return 0;
}