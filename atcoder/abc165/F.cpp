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
int val[200010];
int ans[200010];
int tree[800010];
int tab[200010];
int n,sz;

void upd(int node,int l,int r,int ix)
{
	// cout << l << " " << r << endl;
	if (l == r)
	{
		tree[node] = tab[l];
		return;
	}
	int mid = (l + r) >> 1;
	int child = node << 1;
	if (ix > mid)
	{
		// cout << "yo\n";
		// return;
		upd(child | 1,mid + 1,r,ix);
	}
	else
	{
		// cout << "yo\n";
		// return;
		upd(child,l,mid,ix);
	}
	tree[node] = max(tree[child],tree[child | 1]);
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
	if (queryL > queryR) return 0;
	if (queryL > nodeR || queryR < nodeL) return 0;
	if (queryL <= nodeL && nodeR <= queryR) return tree[node];
	int mid = (nodeL + nodeR) >> 1;
	int child = node << 1;
	return max(query(child,nodeL,mid,queryL,queryR),query(child | 1,mid + 1,nodeR,queryL,queryR));
}

void dfs(int node,int par)
{
	int tmp = query(1,1,sz,1,val[node] - 1) + 1;
	ans[node] = tmp;
	if (par != -1)
		ans[node] = max(ans[par],tmp);
	int bef = tab[val[node]];
	tab[val[node]] = tmp;
	upd(1,1,sz,val[node]);
	// cout << "yo\n";
	// return;
	for (auto it : adj[node]) if (it != par)
		dfs(it,node);
	tab[val[node]] = bef;
	upd(1,1,sz,val[node]);
}

map<int,int> mp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector< int > compress;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> val[i];
		compress.push_back(val[i]);
	}
	sort(compress.begin(),compress.end());
	compress.erase(unique(compress.begin(),compress.end()),compress.end());
	sz = compress.size();
	// cout << sz << endl;
	for (int i = 0 ; i < compress.size() ; i++)
		mp[compress[i]] = i + 1;
	for (int i = 1 ; i <= n ; i++)
		val[i] = mp[val[i]];
	for (int i = 1 ; i < n ; i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// return 0;
	// return 0;
	dfs(1,-1);
	for (int i = 1 ; i <= n ; i++)
		cout << ans[i] << endl;
	return 0;
}