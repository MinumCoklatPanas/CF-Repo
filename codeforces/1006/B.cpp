#include <bits/stdc++.h>
using namespace std;

pair<int,int> posi[2010];
int tab[2010];

bool cmp(pair<int,int> p,pair<int,int> q)
{
	if (p.first==q.first) return p.second<q.second;
	return (p.first>q.first);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>tab[i];
		posi[i].first=tab[i];
		posi[i].second=i;
	}
	sort(posi+1,posi+n+1,cmp);
	int sum=0;
	int last=0;
	vector<int> ans;
	vector<int> pos;
	for (int i=1;i<=k;i++)
	{
		sum+=posi[i].first;
		pos.push_back(posi[i].second);
	}
	sort(pos.begin(),pos.end());
	for (int i=0;i<k;i++)
	{
		if (i==k-1)
		 ans.push_back(n-last);
		else
		 ans.push_back(pos[i]-last);
		last=pos[i];
	}
	cout<<sum<<"\n";
	for (int i=0;i<k;i++)
	 cout<<ans[i]<<" ";
	cout<<"\n";
}