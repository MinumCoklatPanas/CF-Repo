#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cei(ll a,ll b)
{
	return (a/b)+(a%b!=0);
}

ll tab[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll mn=1e18;
	ll n,s;
	cin>>n>>s;
	ll tot=0;
	for (ll i=1;i<=n;i++)
	{
		cin>>tab[i];
		mn=min(mn,tab[i]);
		tot+=tab[i];
	}
	if (tot<s)
		cout<<-1<<"\n";
	else
	{
		s-=tot-(mn*n);
		if (s<0)
		{
			cout<<mn<<"\n";
			return 0;
		}
		// assert(s>=0);
		ll ans=mn-cei(s,n);
		cout<<ans<<"\n";
	}
}