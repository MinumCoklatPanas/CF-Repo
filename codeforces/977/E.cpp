#include <bits/stdc++.h>
using namespace std;

vector<int> CC[200010];
int deg[200010];
vector<int> adj[200010];
int pset[200010];
int numset;

int findset(int x)
{
	return (pset[x]==x ? x : pset[x]=findset(pset[x]));
}

void join(int x,int y)
{
	if (findset(x)==findset(y)) return;
	int px=findset(x);
	int py=findset(y);
	pset[px]=py;
	return;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	numset=n;
	for (int i=1;i<=n;i++)
	 pset[i]=i;
	for (int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		++deg[a];
		++deg[b];
		join(a,b);
	}
	for (int i=1;i<=n;i++)
	{
		pset[i]=findset(i);
		CC[pset[i]].push_back(i);
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (CC[i].size()<=2) continue;
		bool ya=true;
//		cout<<i<<" i\n";
		for (int j=0;j<CC[i].size();j++)
		 {
//		 	cout<<CC[i][j]<<"\n";
		 	if (deg[CC[i][j]]!=2)
			 {
			 	ya=false;
			 	break;
			 }
		 }
//		cout<<i<<" "<<ya<<"\n";
		ans+=ya;
	}
	cout<<ans<<"\n";
}
