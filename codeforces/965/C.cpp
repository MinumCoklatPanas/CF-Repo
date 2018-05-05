#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,k,m,d;

ll cei(ll x,ll y)
{
	return (x/y)+(x%y!=0);
}

ll f(ll x)
{
	return cei(n/x,k);
}

int main()
{
	cin>>n>>k>>m>>d;
//	cout<<f(10)<<"\n";
	ll ans=0;
	for (ll i=1;i<=d;i++)
	{
		ll l=1;
		ll r=m;
//		cout<<i<<" i\n";
		while (r-l>1)
		{
			ll mid=(l+r)>>1;
//			cout<<l<<" "<<r<<" "<<mid<<" "<<f(mid)<<" l r mid f\n";
			if (f(mid)<i)
			 r=mid;
			else
			 l=mid;
		}
//		cout<<r<<" "<<f(r)<<" r f\n";
		ll kali=-1;
		if (f(r)==i)
		 kali=r;
		else
		 if (f(l)==i)
		  kali=l;
		if (kali==-1) continue;
		ll now=kali*i;
		ans=max(ans,now);
	}
	cout<<ans<<"\n";
}
