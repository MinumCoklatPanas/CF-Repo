#include <bits/stdc++.h>
using namespace std;

int pos[55][55];
pair<int,int> tab[55];

bool cmp(pair<int,int> p,pair<int,int> q)
{
	if (p.first==q.first) return p.second<q.second;
	return p.first>q.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i].first>>tab[i].second;
	 	pos[tab[i].first][tab[i].second]++;
	 }
	sort(tab+1,tab+n+1,cmp);
//	cout<<tab[k].first<<" "<<tab[k].second<<"\n";
	cout<<pos[tab[k].first][tab[k].second]<<"\n";
}
