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

vector< ll > adj[200010];
ll depth[200010];
ll subtree[200010];
bool take[200010];

bool cmp(ll a,ll b)
{
	return (depth[a] - subtree[a] > depth[b] - subtree[b]);
}

void dfs(ll u,ll par,ll deep)
{
	subtree[u] = 1;
	depth[u] = deep;
	for (ll it : adj[u]) if (it != par)
	{
		dfs(it,u,deep + 1);
		subtree[u] += subtree[it];
	}
}

ll ans = 0;
void dfs2(ll u,ll par,ll pass)
{
	ans += pass * take[u];
	// if (take[u])
	// 	cout << pass
	for (auto it : adj[u]) if (it != par)
	{
		dfs2(it,u,pass + (!take[u]));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin >> n >> k;
	for (ll i = 1 ; i < n ; i++)
	{
		ll a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,-1,0);
	vector< ll > tmp;
	for (ll i = 1 ; i <= n ; i++)
	{
		tmp.push_back(i);
		// cout << subtree[i] << endl;
	}
	sort(tmp.begin(),tmp.end(),cmp);
	for (ll i = 0 ; i < k ; i++)
	{
		// cout << tmp[i] << endl;
		take[tmp[i]] = 1;
	}
	dfs2(1,-1,0);
	cout << ans << endl;
	return 0;
}