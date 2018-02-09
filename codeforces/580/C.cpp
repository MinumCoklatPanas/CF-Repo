#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
bool vis[100010];
int par[100010];
bool ada[100010];
int num[100010];
int ans=0;
int n,m;

void dfs(int u,int mx,int cur)
{
	vis[u]=1;
//	cout<<u<<" "<<mx<<" "<<cur<<"\n";
	bool leaf=true;
//	cout<<"\n";
	for (int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if (vis[v]) continue;
//		cout<<u<<" "<<v<<"\n";
		leaf=false;
//		if (!ada[v])
//		 cur=0;
//		else
//		 ++cur;
//		mx=max(mx,cur);
		dfs(v,max(mx,ada[v] ? cur+1 : 0),ada[v] ? cur+1 : 0);
	}
//	cout<<leaf<<" leaf\n";
	if (leaf && mx<=m)
	{
//		cout<<u<<" u\n";
		++ans;
	}
	return;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 cin>>ada[i];
	for (int i=1;i<n;i++)
	 {
	 	int a,b;
	 	cin>>a>>b;
	 	adj[a].push_back(b);
	 	adj[b].push_back(a);
	 }
	if (ada[1])
	 dfs(1,1,1);
	else
	 dfs(1,0,0);
	cout<<ans<<"\n";
}
