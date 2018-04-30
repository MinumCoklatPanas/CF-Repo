#include <bits/stdc++.h>
using namespace std;

pair<int,int> tab[5010];
bool sudah[5010];
map<int,bool> ada;

bool cmp(pair<int,int> p,pair<int,int> q)
{
	if (p.first==q.first) return p.second<q.second;
	return p.first<q.first;
	
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>tab[i].first>>tab[i].second;
	sort(tab+1,tab+n+1,cmp);
	int now=tab[1].second;
	for (int i=2;i<=n;i++)
	{
		if (tab[i].second>=now)
		 now=tab[i].second;
		else
		 now=tab[i].first;
	}
	cout<<now<<"\n";
}
