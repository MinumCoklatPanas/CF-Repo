#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b)
{
	return (b==0 ? a : gcd(b,a%b));
}

int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	ll fpb=gcd(a,b);
//	cout<<n<<" "<<a<<" "<<b<<"\n";
//	cout<<fpb<<"\n";
	if (n%fpb!=0)
	{
		cout<<"NO\n";
		return 0;
	}
	n/=fpb;
	a/=fpb;
	b/=fpb;
	for (ll i=0;i<=n;i++)
	{
		ll sisa=n-(a*i);
		if (sisa<0)
		{
			cout<<"NO\n";
			return 0;
		}
		if (sisa%b==0)
		{
			cout<<"YES\n";
			cout<<i<<" "<<sisa/b<<"\n";
			return 0;
		}
	}
}
