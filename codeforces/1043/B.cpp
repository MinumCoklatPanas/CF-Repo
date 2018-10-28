#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[1010];
ll pref[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for (ll i=1;i<=n;i++)
		 {
		 	cin>>a[i];
		 	pref[i]=a[i]+pref[i-1];
		 }
	vector<ll> ans;
	ans.clear();
	for (ll i=1;i<n;i++)
	{
		ll now=a[i];
		bool ya=true;
		for (int j=i+1;j<=n;j++)
		{
			ll mod=j%i;
			if (mod==0)
				 mod=i;
			// cout<<i<<" "<<j<<" "<<mod<<"\n";
			if (now+a[mod]!=a[j])
			{
				// cout<<now<<" now\n";
				// cout<<i<<" "<<j<<" "<<mod<<" wtf\n";
				ya=false;
				break;
			}
			if (mod==i)
				now=a[j];
		}
		if (ya)
			 ans.push_back(i);
	}
	ans.push_back(n);
	cout<<ans.size()<<"\n";
	for (ll i=0;i<ans.size();i++)
		{
			if (i==0)
				 cout<<ans[i];
			else
				 cout<<" "<<ans[i];
		}
	cout<<"\n";
}