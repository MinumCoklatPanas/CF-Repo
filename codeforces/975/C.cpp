#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n,q;
	cin>>n>>q;
	vector<ll> tab(n+2);
	vector<ll> pref(n);
	for (int i=0;i<n;i++)
	 cin>>tab[i];
	pref[0]=tab[0];
	for (int i=1;i<n;i++)
	 pref[i]=pref[i-1]+tab[i];
	ll now=0;
	for (int i=1;i<=q;i++)
	{
		ll k;
		cin>>k;
		now+=k;
		ll ix=upper_bound(pref.begin(),pref.end(),now)-pref.begin()-1;
		ll left=n-ix-1;
		if (left<=0)
		 {
		 	left=n;
		 	now=0;
		 }
		cout<<left<<"\n";
	}
}
