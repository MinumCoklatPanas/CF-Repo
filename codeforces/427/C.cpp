#include <bits/stdc++.h>
using namespace std;

const
 long long MOD=1e9+7;

vector<long long> adj[100010];
long long dfs_num[100010];
long long dfs_low[100010];
bool vis[100010];
vector< vector<long long> > SCC;
long long cost[100010];
vector<long long> MinSCC;
long long VisitKe;
stack<long long> st;
bool ada[100010];
long long ans2=0;

void reset()
{
	memset(adj,0,sizeof(adj));
	memset(dfs_num,0,sizeof(dfs_num));
	memset(dfs_low,0,sizeof(dfs_low));
	memset(vis,0,sizeof(vis));
	SCC.clear();
	memset(cost,0,sizeof(cost));
	MinSCC.clear();
	VisitKe=1;
	memset(ada,0,sizeof(ada));
	ans2=0;
}

void Tarjan(long long u)
{
//	cout<<u<<" u\n";
	dfs_num[u]=dfs_low[u]=VisitKe++;
	st.push(u); ada[u]=1;
	vis[u]=1;
	for (long long i=0;i<adj[u].size();i++)
	{
		long long v=adj[u][i];
//		cout<<v<<" v\n";
		if (!vis[v])
		 Tarjan(v);
		if (ada[v])
		 dfs_low[u]=min(dfs_low[u],dfs_low[v]);
	}
	if (dfs_num[u]==dfs_low[u])
	{
		long long mn=MOD;
		vector<long long> tmp;
		while (st.top()!=u)
		{
			tmp.push_back(st.top());
			ada[st.top()]=0;
			mn=min(mn,cost[st.top()]);
			st.pop();
		}
		st.pop();
		tmp.push_back(u);
		ada[u]=0;
		mn=min(mn,cost[u]);
//		ans2+=mn;
		MinSCC.push_back(mn);
		SCC.push_back(tmp);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin>>n;
	reset();
	for (long long i=1;i<=n;i++)
	 cin>>cost[i];
	long long m;
	cin>>m;
	for (long long i=1;i<=m;i++)
	{
		long long a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for (long long i=1;i<=n;i++)
	{
		if (!vis[i])
		 {
//		 	cout<<i<<" i\n";
		 	Tarjan(i);
		 }
	}
	long long ans=1;
	for (long long i=0;i<SCC.size();i++)
	{
		long long mn=MinSCC[i];
		ans2+=mn;
//		ans2%=MOD;
		long long jumlah=0;
		for (long long j=0;j<SCC[i].size();j++)
		 jumlah+=(cost[SCC[i][j]]==mn);
		ans*=jumlah;
		ans%=MOD;
	}
	ans%=MOD;
//	ans2%=MOD;
//	cout<<SCC.size()<<"\n";
//	for (long long i=0;i<SCC.size();i++)
//	 for (long long j=0;j<SCC[i].size();j++)
//	 {
//	 	if (j==SCC[i].size()-1)
//	 	 cout<<SCC[i][j]<<"\n";
//	 	else
//	 	 cout<<SCC[i][j]<<" ";
//	 }
	cout<<ans2<<" "<<ans<<"\n";
}
