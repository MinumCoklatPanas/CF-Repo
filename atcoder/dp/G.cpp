#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
bool vis[100010];
vector<int> sorted;
int DP[100010];
int n,m;

void topovisit(int u)
{
	vis[u]=1;
	for (int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (!vis[v])
		 topovisit(v);
	}
	sorted.push_back(u);
}

void SORT()
{
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
	  	 topovisit(i);
	  	DP[i] = 0;
	}
	reverse(sorted.begin(),sorted.end());
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i ++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	SORT();
	int ans = 0;
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < adj[sorted[i]].size() ; j++)
		{
			DP[adj[sorted[i]][j]] = max(DP[adj[sorted[i]][j]],DP[sorted[i]] + 1);
		}
	}
	for (int i = 1 ; i <= n ; i++)
		ans = max(ans,DP[i]);
	cout << ans << endl;
}