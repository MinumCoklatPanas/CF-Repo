#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;

vector<int> dist[100010];
vector<int> adj[100010];
int a[100010];
bool vis[100010];
queue< pair<int,int> > q;
vector<int> vert[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n,m,k,s;
	cin>>n>>m>>k>>s;
	for (int i=1;i<=n;i++)
	 dist[i].resize(k+5,1000000);
	for (int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	vert[a[i]].push_back(i);
	 	dist[i][a[i]]=0;
	 }
	for (int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=0;j<vert[i].size();j++)
		 {
		 	q.push({vert[i][j],0});
		 }
		while (!q.empty())
		{
			pair<int,int> depan=q.front();
			q.pop();
			int u=depan.first;
			int step=depan.second;
//			dist[u][i]=step;
			vis[u]=1;
			++step;
			for (int l=0;l<adj[u].size();l++)
			{
				if (dist[adj[u][l]][i]>step)
				{
					dist[adj[u][l]][i]=step;
					q.push({adj[u][l],step});
				}
			}
		}
	}
//	for (int i=1;i<=n;i++)
//	 {
//	 	for (int j=1;j<=k;j++)
//	 	{
//	 		if (j==k)
//	 		 cout<<dist[i][j]<<"\n";
//	 		else
//	 		 cout<<dist[i][j]<<" ";
//		 }
//	 }
	for (int i=1;i<=n;i++)
	{
		sort(dist[i].begin()+1,dist[i].begin()+k+1);
		int ans=0;
		for (int j=0;j<s;j++)
		 ans+=dist[i][1+j];
		if (i==n)
		 cout<<ans<<"\n";
		else
		 cout<<ans<<" ";
	}
}
