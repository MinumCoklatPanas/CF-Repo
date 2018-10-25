#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC push_options
#pragma GCC pop_options
#pragma GCC reset_options
#pragma GCC optimize ("O3")

typedef long long ll;

ll tab[200010];
ll pref[200010];

ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int main()
{
	// freopen("inputf.in","r",stdin);
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	ll mn=1e12;
	ll n,t;
	n=readInt();
	t=readInt();
	for (ll i=1;i<=n;i++)
	{
		tab[i]=readInt();
		mn=min(mn,tab[i]);
		pref[i]=tab[i]+pref[i-1];
	}
//	cout<<t<<" "<<mn<<"\n";
//	return 0;
	ll ans=0;
	while (t>=mn)
	{
//		cout<<"yo\n";
//		cout<<t<<" t\n";
		ll last=1;
		ll cari=t;
		ll cnt=0;
		ll cnt_ix=0;
		while ((last<=n) && (cari>=mn))
		{
			if (tab[last]<=t)
			{
				ll cari2=cari+pref[last-1];
//				cout<<
				ll ix=upper_bound(pref+last,pref+n+1,cari2)-pref-1;
//				cout<<ix<<" ix\n";
				cari-=pref[ix]-pref[last-1];
				cnt+=pref[ix]-pref[last-1];	
				cnt_ix+=ix-last+1;			
				last=ix+2;
			}
			else
				 last++;
		}
		ll putaran=t/cnt;
		ans+=putaran*cnt_ix;
		t%=cnt;
	}
	printf("%lld\n",ans);
}
