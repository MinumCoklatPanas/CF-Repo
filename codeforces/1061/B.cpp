#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tab[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll mx=0;
	for (ll i=1;i<=n;i++)
	{
		 cin>>tab[i];
		 mx=max(mx,tab[i]);
	}
	sort(tab+1,tab+n+1);
	ll ans=0;
	ll ambil=1;
	for (ll i=1;i<=n;i++)
	{
		if (ambil>mx)
		{
			ans+=tab[i]-1;
		}
		else
		{
			if (tab[i]<ambil)
			{
				ans+=tab[i]-1;
				continue;
			}
			if (i==n && ambil<mx)
			 ans+=ambil-1;
			else
			 ans+=tab[i]-1;
			++ambil;
		}
	}
	cout<<ans<<"\n";
}