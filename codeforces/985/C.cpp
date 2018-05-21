#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tab[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	ll n,k,l;
	cin>>n>>k>>l;
	for (int i=1;i<=n*k;i++)
	 cin>>tab[i];
	sort(tab+1,tab+(n*k)+1);
	int pos=1;
	for (int i=1;i<=n*k;i++)
	{
		if (tab[i]-tab[1]>l) break;
		pos=i;
	}
//	if (n==1)
//	{
//		cout<<tab[1]<<"\n";
//		return 0;
//	}
//	cout<<pos<<" pos\n";
	if (pos<n)
	 cout<<0<<"\n";
	else
	{
		ll ans=0;
		int cnt=0;
		int sisa=(n*k)-pos;
//		cout<<pos<<" pos\n";
		for (int i=pos;i>=1;i--)
		{
			if (sisa>=k-1)
			{
//				cout<<i<<" i\n";
				ans+=tab[i];
				++cnt;
				sisa-=k-1;
			}
			else
			{
				++sisa;
			}
		}
//		cout<<ans<<"\n";
		if (cnt==n)
		 cout<<ans<<"\n";
		else
		 cout<<0<<"\n";
	}
}
