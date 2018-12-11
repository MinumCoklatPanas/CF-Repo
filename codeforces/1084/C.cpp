#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const
 ll MOD=1e9+7;

ll add(ll x,ll y)
{
	return ((x%MOD)+(y%MOD))%MOD;
}

ll mul(ll x,ll y)
{
	return ((x%MOD)*(y%MOD))%MOD;
}

ll sub(ll x,ll y)
{
	ll res=((x%MOD)-(y%MOD))%MOD;
	if (res<0)
		return res+MOD;
	else
		return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector< pair<ll,bool> > angka;
	string s;
	cin>>s;
	ll i=0;
	bool ada=1;
	while (i<s.length())
	{
		char now=s[i];
		ll cnt=0;
		while (s[i]==now & i<s.length())
		{
			cnt++;
			i++;
		}
		if (now=='b')
			ada=1;
		if (now=='a')
		{
			if (ada)
				angka.push_back(make_pair(cnt,ada));
			else
				angka.back().first+=cnt;
			ada=0;
		}
	}
	ll sum=0;
	ll LastSum=0;
	vector< ll > Pertambahans;
	vector< ll > Sums;
	// cout<<angka.size()<<"\n";
	for (ll i=0;i<angka.size();i++)
	{
		// cout<<angka[i].first<<" wat\n";
		sum=add(sum,add(angka[i].first,mul(angka[i].first,sum)));
		// Sums.push_back(sum);
	}
	// cout<<sum<<" sum\n";
	// i=0;
	// while (i<angka.size())
	// {
	// 	if (!angka[i].second)
	// 	{
	// 		ll tmp=0;
	// 		ll simpan=angka[i-1].first;
	// 		// cout<<i<<" i\n";
	// 		while (!angka[i].second && i<angka.size())
	// 		{
	// 			tmp=add(tmp,add(angka[i].first,mul(angka[i].first,tmp)));
	// 			tmp=sub(tmp,angka[i].first);
	// 			++i;
	// 		}
	// 		cout<<tmp<<" tmp\n";
	// 		sum=sub(sum,tmp);
	// 		sum=add(sum,simpan);
	// 	}
	// 	else
	// 	 ++i;
	// }
	cout<<sum<<"\n";
}
