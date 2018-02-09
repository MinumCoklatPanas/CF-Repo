#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

	pair<ll,ll> tab[100010];
	ll M[100010];
	ll S[100010];
	ll pref[100010];
int main()
{
//	freopen("input.txt","r",stdin);
	ll n,d;
	cin>>n>>d;
	for (int i=1;i<=n;i++)
	 cin>>tab[i].first>>tab[i].second;
	sort(tab+1,tab+n+1);
	for (int i=1;i<=n;i++)
	{
		M[i]=tab[i].first;
		S[i]=tab[i].second;
	}
	pref[1]=S[1];
	for (int i=2;i<=n;i++)
	 pref[i]=S[i]+pref[i-1];
	ll ans=-1;
//	return 0;
	for (int i=1;i<=n;i++)
	{
		ll cari=M[i]+d-1;
		ll pos=upper_bound(M+1,M+n+1,cari)-M-1;
		ll count=pref[pos]-pref[i-1];
		ans=max(ans,count);
	}
	cout<<ans<<"\n";
}
