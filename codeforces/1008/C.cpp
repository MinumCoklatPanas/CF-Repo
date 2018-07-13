#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,ll> frek;
ll tab[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	ll mn=1e18;
	for (ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		mn=min(a,mn);
		frek[a]++;
		tab[i]=a;
	}
	ll mx=0ll;
	for (int i=1;i<=n;i++)
	 mx=max(mx,frek[tab[i]]);
	cout<<n-mx<<"\n";
}