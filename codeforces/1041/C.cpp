#include <bits/stdc++.h>
using namespace std;

int tab[200010];
int ans[200010];
pair<int,int> sorted[200010];
int urut[200010];
int ix[200010];
//int last[200010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m,d;
	cin>>n>>m>>d;
	for (int i=1;i<=n;i++)
	{
		cin>>tab[i];
		sorted[i]={tab[i],i};
		urut[i]=tab[i];
	}
	sort(sorted+1,sorted+n+1);
	sort(urut+1,urut+n+1);
	memset(ix,-1,sizeof(ix));
	ix[1]=1;
	ans[sorted[1].second]=1;
	int day=1;
	int last;
	for (int i=1;i<=n;i++)
	{
		if (i==1)
		{
			int idx=lower_bound(urut+1,urut+n+1,urut[i]+d+1)-urut;
//			cout<<idx<<" idx\n";
			last=idx;
			ix[idx]=ix[i];
		}
		else
		{
			if (ix[i]==-1)
			{
				ix[i]=++day;
			}
			int idx=lower_bound(urut+1,urut+n+1,urut[i]+d+1)-urut;
//			cout<<i<<" "<<idx<<" "<<last<<"\n";
			if (ix[idx]!=-1)
			 idx=++last;
			ix[idx]=ix[i];
			ans[sorted[i].second]=ix[i];
			last=idx;
		}
//		for (int j=1;j<=n;j++)
//		 cout<<ix[j]<<" ";
//		cout<<"\n";
	}
	cout<<day<<"\n";
	for (int i=1;i<=n;i++)
	{
		if (i==n)
		 cout<<ans[i]<<"\n";
		else
		 cout<<ans[i]<<" ";
	}
}