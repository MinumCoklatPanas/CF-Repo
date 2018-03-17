#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll x,ll y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}

ll tab[100010];

int main()
{
	set<ll> st;
	int n;
	cin>>n;
	tab[0]=0;
	ll fpb=0;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 }
	sort(tab+1,tab+n+1);
	tab[0]=0;
	for (int i=2;i<=n;i++)
	{
		st.insert(tab[i]-tab[i-1]);
		fpb=gcd(tab[i]-tab[i-1],fpb);
	}
	if (st.size()==1)
	 cout<<0<<"\n";
	else
	 {
	 	ll ans=0;
	 	for (int i=2;i<=n;i++)
	 	{
	 		ll diff=tab[i]-tab[i-1];
	 		ans+=(diff/fpb)-1;
	 	}
	 	cout<<ans<<"\n";
	 }
}