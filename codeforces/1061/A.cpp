#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,s;
	cin>>n>>s;
	ll ans=(ll)1e18;
	for (ll i=1;i<=n;i++)
	{
		ll ambil=(s/i)+(s%i!=0);
		ans=min(ans,ambil);
	}
	cout<<ans<<"\n";

}