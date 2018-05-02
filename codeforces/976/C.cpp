#include <bits/stdc++.h>
using namespace std;

vector< pair< pair<int,int>,int > > cari;
pair< pair<int,int>,int > tab[300010];

bool cmp(pair< pair<int,int>,int > p,pair< pair<int,int>,int > q)
{
	return ((p.first.first<=q.first.first) && (p.first.second>=q.first.second) && (p.second!=q.second));
}

bool comp(pair< pair<int,int>,int > p,pair< pair<int,int>,int > q)
{
	if (p.first.first==q.first.first) return p.first.second>q.first.second;
	return p.first.first<q.first.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i].first.first>>tab[i].first.second;
	 	cari.push_back({{tab[i].first.first,tab[i].first.second},i});
	 	tab[i].second=i;
	 }
	sort(cari.begin(),cari.end(),comp);
	int kanan=cari[0].first.second;
	int ix=cari[0].second;
	for (int i=1;i<n;i++)
	{
		if (cari[i].first.second<=kanan)
		{
			cout<<cari[i].second<<" "<<ix<<"\n";
			return 0;
		}
		if (cari[i].first.second>kanan)
		{
			kanan=cari[i].first.second;
			ix=cari[i].second;
		}
	}
	cout<<-1<<" "<<-1<<"\n";
}
