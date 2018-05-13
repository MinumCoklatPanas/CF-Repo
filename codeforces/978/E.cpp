#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tab[1010];

int main()
{
	ll n,w;
	cin>>n>>w;
	ll mn=1e18;
	ll mx=-mn;
	for (int i=1;i<=n;i++)
	{
		cin>>tab[i];
		tab[i]+=tab[i-1];
		mx=max(tab[i],mx);
		mn=min(tab[i],mn);
	}
	ll bawah=max(0ll,-mn);
	ll atas=min(w-mx,w);
	if (bawah>w || atas<0 || atas<bawah)
	 cout<<0<<"\n";
	else
	 cout<<atas-bawah+1<<"\n";
}
