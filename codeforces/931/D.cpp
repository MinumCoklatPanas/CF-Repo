#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
bool vis[100010];
int step[100010];
queue< pair<int,int> > q;

void bfs()
{
	q.push({1,1});
	while (!q.empty())
	{
		pair<int,int> depan=q.front();
		q.pop();
		int u=depan.first;
		int dist=depan.second;
		step[dist]++;
		vis[u]=1;
		for (int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			if (!vis[v])
			{
				q.push({v,dist+1});
				vis[v]=1;
			}
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=2;i<=n;i++)
	{
		int k;
		cin>>k;
		adj[k].push_back(i);
	}
	bfs();
	int ans=0;
	for (int i=1;i<=100000;i++)
	 ans+=step[i]%2;
	cout<<ans<<"\n";
}
