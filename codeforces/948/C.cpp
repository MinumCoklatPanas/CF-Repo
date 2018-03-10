#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kali[100010];
ll parsial[100010];
ll ans[100010];
ll pref[100010];
ll melt[100010];
ll tab[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	
	 for (int i=1;i<=n;i++)
	  cin>>melt[i];
	
	 pref[1]=melt[1];
	for (int i=2;i<=n;i++)
	  pref[i]=pref[i-1]+melt[i];
//	return
	ll tambah=0;
	for (int i=1;i<=n;i++)
	{
//		cout<<i<<" i\n";
		ll pos=upper_bound(pref+1,pref+n+1,tab[i]+tambah)-pref;
//		cout<<i<<" "<<pos<<"\n";
		kali[i]+=1;
		kali[pos]-=1;
		ll habis=pref[pos-1]-pref[i-1];
		parsial[pos]+=abs(habis-tab[i]);
		tambah+=melt[i];
	}
//	return 0;
	for (int i=1;i<=n;i++)
	 kali[i]=kali[i-1]+kali[i];
//	for (int i=1;i<=n;i++)
//	 cout<<kali[i]<<" ";
//	cout<<"\n";
	for (int i=1;i<=n;i++)
	 ans[i]=melt[i]*kali[i]+parsial[i];
	for (int i=1;i<=n;i++)
	 {
	 	if (i==n)
	 	 cout<<ans[i]<<"\n";
	 	else
	 	 cout<<ans[i]<<" ";
	 }
}
