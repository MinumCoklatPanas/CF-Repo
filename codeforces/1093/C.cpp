#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tab[200010];
ll a[400010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	n/=2;
	for (ll i=1;i<=n;i++)
		cin>>tab[i];
	ll m=2*n;
	a[1]=0;
	a[m]=tab[1];
	for (ll i=2;i<=n;i++)
	{
		a[i]=a[i-1];
		a[m-i+1]=tab[i]-a[i];
		if (a[m-i+1]>a[m-i+2])
		{
			a[i]+=a[m-i+1]-a[m-i+2];
			a[m-i+1]-=a[m-i+1]-a[m-i+2];
		}
	}
	for (ll i=1;i<=m;i++)
	{
		if (i==m)
			cout<<a[i]<<"\n";
		else
			cout<<a[i]<<" ";
	}
}