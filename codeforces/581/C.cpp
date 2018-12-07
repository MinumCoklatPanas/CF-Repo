#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// clock_t satu = clock();
	pair<ll,ll> tab[100010];
	ll n,k;
	cin>>n>>k;
	for (ll i=1;i<=n;i++)
	{
		cin>>tab[i].second;
		ll atas=(tab[i].second/10)+(tab[i].second%10!=0);
		atas*=10;
		tab[i].first=atas-tab[i].second;
	}
	sort(tab+1,tab+n+1);
	for (int i=1;i<=n;i++)
	{
		if (tab[i].first==0) continue;
		// cout<<tab[i].first<<" "<<i<<" "<<tab[i].second<<"\n";
		if (k<=0) break;
		if (tab[i].first>=k)
		{
			tab[i].second+=k;
			tab[i].first=0;
			k=0;
		}
		else
		{
			tab[i].second+=tab[i].first;
			k-=tab[i].first;
			tab[i].first=0;
		}
	}
	k-=k%10;
	// cout<<k<<" k\n";
	sort(tab+1,tab+n+1);
	for (int i=1;i<=n;i++)
	{
		// cout<<tab[i].second<<"\n";
		// assert(tab[i].second%10==0);
		int sisa=100-tab[i].second;
		if (sisa>k)
		{
			tab[i].second+=k;
			break;
		}
		else
		{
			tab[i].second+=sisa;
			k-=sisa;
		}
	}	
	int ans=0;
	for (int i=1;i<=n;i++)
		ans+=(tab[i].second/10);
	cout<<ans<<"\n";
}