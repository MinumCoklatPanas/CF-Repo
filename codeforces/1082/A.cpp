#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,x,y,d;
		cin>>n>>x>>y>>d;
		if ((abs(x-y)%d!=0) && (abs(n-y)%d!=0) && (abs(1-y)%d!=0))
		{
			cout<<-1<<"\n";
			continue;
		}
		ll ans=(ll)1e18;
		if (abs(x-y)%d==0)
		{
			ll step=abs(x-y)/d;
			ans=min(ans,step);
		}
		if (abs(n-y)%d==0)
		{
			ll step=(abs(n-x)/d)+(abs(n-x)%d!=0);
			step+=abs(n-y)/d;
			ans=min(ans,step);
		}
		if (abs(1-y)%d==0)
		{
			ll step=(abs(1-x)/d)+(abs(1-x)%d!=0);
			step+=abs(1-y)/d;
			ans=min(ans,step);
		}
		cout<<ans<<"\n";
	}
}