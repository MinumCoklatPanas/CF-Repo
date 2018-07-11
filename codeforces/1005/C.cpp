#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,ll> ada;
ll tab[120010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	ll mx=0ll;
	for (ll i=1;i<=n;i++)
	{
		cin>>tab[i];
		ada[tab[i]]+=1;
		mx=max(mx,tab[i]);
	}
	ll ans=0;
	for (ll i=1;i<=n;i++)
	{
		ll cari=1;
		bool ya=false;
		--ada[tab[i]];
//		cout<<tab[i]<<" i\n";
		while (cari<(ll)1e10)
		{
//			cout<<cari<<" cari\n";
			ll sisa=cari-tab[i];
//			cout<<sisa<<" sisa\n";
			if (ada[sisa])
			{
//				cout<<sisa<<" sisa\n";
				ya=true;
				break;
			}
			cari<<=1ll;
		}
//		if (!ya)
//		 cout<<tab[i]<<"\n";
		ans+=!ya;
		++ada[tab[i]];
	}
	cout<<ans<<"\n";
}