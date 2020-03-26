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

vector< int > adj[200010];
int depth[200010];
int spa[20][200010];
int LOG = 19;
int n,q,k;

void dfs(int u,int par,int deep)
{
	spa[0][u] = par;
	depth[u] = deep;
	for (int next : adj[u]) if (next != par)
	{
		dfs(next,u,deep + 1);
	}
}	

void precompute()
{
	memset(spa,-1,sizeof(spa));
	dfs(1,-1,1);
	for (int i = 1 ; i <= LOG ; i++)
		for (int j = 1 ; j <= n ; j++) if (spa[i - 1][j] != -1)
			spa[i][j] = spa[i - 1][spa[i - 1][j]];
}

int getLCA(int u,int v)
{
	if (depth[u] < depth[v]) swap(u,v);
	for (int i = LOG ; i >= 0 ; i--) if (depth[u] - (1 << i) >= depth[v])
		u = spa[i][u];
	if (u == v) return u;
	for (int i = LOG ; i >= 0 ; i--) if (spa[i][u] != spa[i][v] && spa[i][u] != -1)
	{
		u = spa[i][u];
		v = spa[i][v];
	}
	return spa[0][u];
}

bool cmp(int a,int b)
{
	return (depth[a] > depth[b]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1 ; i < n ; i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	precompute();
	while (q--)
	{
		vector< int > nodes;
		cin >> k;
		for (int i = 1 ; i <= k ; i++)
		{
			int ta;
			cin >> ta;
			nodes.push_back(ta);
		}
		sort(nodes.begin(),nodes.end(),cmp);
		int curLCA = nodes[0];
		bool can = 1;
		for (int i = 1 ; i < k ; i++)
		{
			curLCA = getLCA(curLCA,nodes[i]);
			if (curLCA == nodes[i] || spa[0][nodes[i]] == curLCA)
				continue;
			else
			{
				can = 0;
				break;
			}
		}
		if (can)
			cout <<"YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}