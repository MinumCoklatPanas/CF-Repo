#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,ll> mp;

int main()
{
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	set<ll> nums;
	for (ll i=1;i<=n;i++)
	{
		ll a,x;
		cin>>a>>x;
		mp[a]=max(mp[a],x);
		nums.insert(a);
	}
	ll m;
	cin>>m;
	for (ll i=1;i<=m;i++)
	{
		ll a,x;
		cin>>a>>x;
		mp[a]=max(mp[a],x);
		nums.insert(a);
	}
	ll ans=0;
	for (set<ll>::iterator it=nums.begin();it!=nums.end();++it)
	{
		ll now=*it;
		ans+=mp[now];
	}
	cout<<ans<<"\n";
}
