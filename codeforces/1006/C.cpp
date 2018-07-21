#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tab[200010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	if (n==1)
	{
		cout<<0<<"\n";
		return 0;
	}
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	tab[i]+=tab[i-1];
	 }
		ll mx=0ll;
		for (int i=n-1;i>=1;i--)
		{
			ll now=tab[i];
			ll l=i+1;
			ll r=n;
			ll mid=(l + r)>>1;
			while (l<=r)
			{
				ll cari=tab[n]-tab[mid-1];
				if (cari==now)
				{
					cout<<now<<"\n";
					return 0;
				}
				else
				 if (cari>now)
				  l=mid+1;
				 else
				  r=mid-1;
				mid=(l + r)>>1;
			}
		}
		cout<<0<<"\n";
}