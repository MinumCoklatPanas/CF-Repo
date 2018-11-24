#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum(ll x,ll y)
{
	if (x>y) return 0ll;
	// assert(x<=y);
	ll num=y-x;
	num/=2;
	num++;
	ll sum=x+y;
	ll res=(sum*num)/2;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll q;
	cin>>q;
	while (q--)
	{
		ll L,R;
		cin>>L>>R;
		ll KiGe,KiGa,KaGe,KaGa;
		if (L%2==0)
		{
			KiGe=L;
			KiGa=L+1;
		}
		else
		{
			KiGe=L+1;
			KiGa=L;
		}
		if (R%2==0)
		{
			KaGe=R;
			KaGa=R-1;
		}
		else
		{
			KaGe=R-1;
			KaGa=R;
		}
		ll ans=(-1ll*sum(KiGa,KaGa))+(sum(KiGe,KaGe));
		cout<<ans<<"\n";
	}
}