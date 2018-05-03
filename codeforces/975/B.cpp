#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
//	freopen("input.txt","r",stdin);
	ll tab[20];
	ll kop[20];
	for (int i=1;i<=14;i++)
	 cin>>tab[i];
	ll ans=0;
	for (int i=1;i<=14;i++)
	{
		if (!tab[i]) continue;
		for (int j=1;j<=14;j++)
		 kop[j]=tab[j];
		kop[i]=0;
		ll bagi=tab[i]/14;
		for (int j=1;j<=14;j++)
		{
			int ix=(i+j)%14;
			if (ix==0)
			 ix=14;
			kop[ix]+=bagi;
		}
		ll mod=tab[i]%14;
		for (int j=1;j<=mod;j++)
		{
			int ix=(i+j)%14;
			if (ix==0)
			 ix=14;
			kop[ix]++;
		}
		ll sum=0;
		for (int j=1;j<=14;j++)
		 sum+=(kop[j]%2==0)*kop[j];
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
}
