#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tab[200010];
ll pref[200010];

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	pref[1]=tab[1];
	for (int i=2;i<=n;i++)
	 pref[i]=pref[i-1]+tab[i];
	for (int i=1;i<=m;i++)
	{
		ll a;
		cin>>a;
		ll pos=lower_bound(pref+1,pref+n+1,a)-pref;
		cout<<pos<<" ";
		cout<<a-pref[pos-1]<<"\n";
	}
}
