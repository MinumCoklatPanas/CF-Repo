#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const
 long double EPS=1e-18;
 
long double slope(ll x1,ll y1,ll x2,ll y2)
{
	return (long double)(x2-x1)/(long double)(y2-y1);
}

pair< pair<ll,ll>,ll > tab[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	for (ll i=1;i<=n;i++)
	 {
	 	cin>>tab[i].first.first>>tab[i].first.second;
	 	tab[i].second=i;
	 }
	sort(tab+1,tab+n+1);
	cout<<tab[1].second<<" "<<tab[2].second<<" ";
	long double d=slope(tab[1].first.first,tab[1].first.second,tab[2].first.first,tab[2].first.second);
	for (ll i=3;i<=n;i++)
	{
		long double dd=slope(tab[1].first.first,tab[1].first.second,tab[i].first.first,tab[i].first.second);
		if (d==dd) continue;
		cout<<tab[i].second<<"\n";
		return 0;
	}
}
