#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tab[2010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	bool sudah=true;
	for (ll i=1;i<=n;i++)
	{
		cin>>tab[i];
		tab[i]+=100000;
		if (tab[i]<=tab[i-1] && i>1)
		{
			sudah=false;
		}
	}
	// cout<<sudah<<" sudah\n";
	if (sudah)
	{
		cout<<0<<"\n";
		return 0;
	}
	vector< pair<ll,ll> > update;
	update.push_back(make_pair(1,tab[1]));
	// cout<<2<<" "<<1<<" "<<tab[1];
	ll last=0ll;
	for (ll i=2;i<=n;i++)
	{
		for (ll j=last+1;j<tab[i];j++)
		{
			if (tab[i]%(tab[i]-j)>last)
			{
				update.push_back(make_pair(i,tab[i]-j));
				// cout<<2<<" "<<i<<" "<<(tab[i]-j)<<"\n";
				last=tab[i]%(tab[i]-j);
				break;
			}
		}
	}
	ll res=update.size()+1;
	cout<<res<<"\n";
	cout<<1<<" "<<n<<" "<<100000<<"\n";
	for (ll i=0;i<update.size();i++)
		cout<<2<<" "<<update[i].first<<" "<<update[i].second<<"\n";
}