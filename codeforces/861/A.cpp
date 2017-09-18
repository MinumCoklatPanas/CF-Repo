#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll x,ll y)
{
	//cout<<x<<" "<<y<<"\n";
	if (y==0)
	 return x;
	return gcd(y,x%y);
}

ll lcm(ll x,ll y)
{
	ll fpb=gcd(x,y);
	//cout<<fpb<<"\n";
	ll res=(x/fpb)*y;
	return res;
}

int main()
{
	ll n,k;
	cin>>n>>k;
	ll sepuluh=1;
	for (ll i=1;i<=k;i++)
	 sepuluh*=10;
	//cout<<sepuluh<<"\n";
	ll ans=lcm(sepuluh,n);
	cout<<ans<<"\n";
}
