#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<ll> val[100010];
// vector<ll> pref[100010];
ll tot[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for (ll i=1;i<=n;i++)
	{
		ll s,r;
		cin>>s>>r;
		val[s].push(r);
	}
	for (ll i=1;i<=m;i++)
	{
		if (val[i].size()>0)
		{
			ll ix=1;
			ll cnt=0;
			while (!val[i].empty())
			{
				ll depan=val[i].top();
				// cout<<depan<<"\n";
				val[i].pop();
				cnt+=depan;
				if (cnt<0) break;
				// cnt+=depan;
				tot[ix++]+=cnt;
			}
		}
	}
	ll ans=0;
	for (ll i=1;i<=100000;i++)
		ans=max(ans,tot[i]);
	cout<<ans<<"\n";
}