#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const
 ll MOD=1e9+7;

ll add(ll x,ll y)
{
	return ((x%MOD)+(y%MOD))%MOD;
}

ll bisa[1000010];
ll tab[1000010];
ll up[1000010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for (ll i=1;i<=n;i++)
		cin>>tab[i];
	ll ans=0;
	for (ll i=1;i<=n;i++)
	{
		// cout<<i<<"\n";
		for (ll j=1;j*j<=tab[i];j++)
		{
			if (tab[i]%j==0)
			{
				ll sisa=tab[i]/j;
				if (j==1)
				{
					// ans=add(ans,1ll);
					up[j]=add(up[j],1ll);
					// ans=add(ans,bisa[sisa-1]);
					up[sisa]=add(up[sisa],bisa[sisa-1]);
				}
				else
				if (j*j!=tab[i])
				{
					// ans=add(ans,add(bisa[j-1],bisa[sisa-1]));
					up[j]=add(up[j],bisa[j-1]);
					up[sisa]=add(up[sisa],bisa[sisa-1]);
				}
		
				else
				{
					// ans=add(ans,bisa[j-1]);
					up[j]=add(up[j],bisa[j-1]);
				}
				// cout<<i<<" "<<j<<" "<<ans<<" ijans\n";
				// cout<<up[j]<<" "<<up[sisa]<<" up jsisa\n";
				// cout<<bisa[j-1]<<" "<<bisa[sisa-1]<<" bisa jsisa\n";
				// cout<<"\n";
			}
		}
		for (ll j=1;j*j<=tab[i];j++)
		{
			if (tab[i]%j==0)
			{
				ll sisa=tab[i]/j;
				bisa[j]=add(bisa[j],up[j]);
				if (j*j!=tab[i])
					bisa[sisa]=add(bisa[sisa],up[sisa]);
				up[j]=up[sisa]=0ll;
			}
		}
		// cout<<i<<" I\n";
		// for (int j=1;j<=6;j++)
		// 	cout<<bisa[j]<<" ";
		// cout<<"\n";
		// cout<<"\n";
	}
	for (int i=1;i<=1000000;i++)
		ans=add(ans,bisa[i]);
	cout<<ans<<"\n";
}