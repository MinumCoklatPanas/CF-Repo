#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> pos[1000010];
ll BIT[1000010];
vector<ll> compress;
map<ll,ll> mp;
ll len;
ll tab[1000010];
ll n;

void update(ll x,ll val)
{
	for ( ; x<=n; x+=(x&-x))
	 BIT[x]+=val;
}

ll query(ll x)
{
	ll res=0;
	for ( ; x; x-=(x&-x))
	 res+=BIT[x];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for (ll i=1;i<=n;i++)
	{
		cin>>tab[i];
		compress.push_back(tab[i]);
	}
	sort(compress.begin(),compress.end());
	compress.erase(unique(compress.begin(),compress.end()),compress.end());
	for (ll i=0;i<compress.size();i++)
	 mp[compress[i]]=i+1;
	len=compress.size();
	for (ll i=1;i<=n;i++)
	{
		ll posi=mp[tab[i]];
		pos[posi].push_back(i);
	}
	ll ans=0;
	for (ll i=1;i<=n;i++)
	{
		ll ix=mp[tab[i]];
		ll posi=lower_bound(pos[ix].begin(),pos[ix].end(),i)-pos[ix].begin();
		ll kanan=pos[ix].size()-posi;
		ll kiri=posi+1;
//		cout<<kiri<<" "<<kanan<<"\n";
		ans+=query(n)-query(kanan);
		update(kiri,1);
	}
	cout<<ans<<"\n";
}
