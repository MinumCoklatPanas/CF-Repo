#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200010];
int in[200010];
int out[200010];
int balik[200010];
int cnt;

void dfs(int par,int u)
{
	in[u]=cnt;
	balik[cnt++]=u;
	for (int i=0;i<adj[u].size();i++)
	{
		if (adj[u][i]!=par)
		 dfs(u,adj[u][i]);
	}
	out[u]=cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n,q;
	cin>>n>>q;
	for (int i=2;i<=n;i++)
	{
		int a;
		cin>>a;
		adj[a].push_back(i);
	}
	cnt=1;
	dfs(-1,1);
//	for (int i=1;i<=n;i++)
//	 cout<<in[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)
//	 cout<<out[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)
//	 cout<<balik[i]<<" ";
//	cout<<"\n";
	for (int i=1;i<=n;i++)
	 out[i]--;
	while (q--)
	{
		int i,k;
		cin>>i>>k;
		int sum=out[i]-in[i]+1;
//		cout<<i<<" "<<in[i]<<" "<<out[i]<<"\n";
		if (k>sum)
		 cout<<-1<<"\n";
		else
		 {
		 	int ix=in[i]+k-1;
		 	cout<<balik[ix]<<"\n";
		 }
	}
}