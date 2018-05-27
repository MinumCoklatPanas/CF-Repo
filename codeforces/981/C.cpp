#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	 cnt+=(adj[i].size()>2);
	if (cnt>1)
	 cout<<"No\n";
	else
	 {
	 	cout<<"Yes\n";
	 	if (n==2)
	 	{
	 		cout<<"1\n";
	 		cout<<"1 2\n";
	 		return 0;
		}
	 	if (cnt==0)
	 	{
	 		int root;
	 		for (int i=1;i<=n;i++)
	 		 if (adj[i].size()==2)
	 		 {
	 		 	root=i;
	 		 	break;
			 }
			vector<int> edge;
			for (int i=1;i<=n;i++)
			 if (adj[i].size()==1)
			 {
			 	edge.push_back(i);
			 }
			cout<<edge.size()<<"\n";
			for (int i=0;i<edge.size();i++)
			 {
			 	cout<<root<<" "<<edge[i]<<"\n";
			 }
		}
		else
		{
			int root;
			for (int i=1;i<=n;i++)
			{
				if (adj[i].size()>2)
				{
					root=i;
					break;
				}		
			}
			vector<int> edge;
			for (int i=1;i<=n;i++)
			{
				if (adj[i].size()==1)
				{
					edge.push_back(i);
				}
			}
			cout<<edge.size()<<"\n";
			for (int i=0;i<edge.size();i++)
			{
				cout<<root<<" "<<edge[i]<<"\n";
			}
		}
	 }
}
