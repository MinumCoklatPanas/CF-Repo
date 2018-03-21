#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll BIT[200010];
vector<ll> compress;
map<ll,ll> mp;
pair< pair<ll,ll>,ll > tab[200010];
ll n,len;

bool cmp(pair< pair<ll,ll>,ll > p,pair< pair<ll,ll>,ll > q)
{
	if (p.first.second==q.first.second)
	{
		if (p.first.first!=q.first.first) return p.first.first>q.first.first;
		return p.second>q.second;
	}
	return p.first.second>q.first.second;
}

void update(ll x,ll val)
{
	for ( ; x<=len; x+=(x&-x))
	 BIT[x]=max(BIT[x],val);
}

ll query(ll x)
{
	ll res=0;
	for ( ; x; x-=(x&-x))
	 res=max(res,BIT[x]);
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i].first.first>>tab[i].first.second>>tab[i].second;
	 	compress.push_back(tab[i].first.first);
	 	compress.push_back(tab[i].first.second);
	 }
	sort(tab+1,tab+n+1,cmp);
//	for (int i=1;i<=n;i++)
//	 cout<<tab[i].first.first<<" "<<tab[i].first.second<<" "<<tab[i].second<<"\n";
	sort(compress.begin(),compress.end());
	compress.erase(unique(compress.begin(),compress.end()),compress.end());
	len=(ll)compress.size();
	for (int i=0;i<len;i++)
	 mp[compress[i]]=i+1;
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		ll ix_a=mp[tab[i].first.first];
		ll ix_b=mp[tab[i].first.second];
		ll cari=query(ix_b-1);
		ll panjang=cari+tab[i].second;
//		cout<<i<<" "<<cari<<" "<<panjang<<"\n";
		ans=max(ans,panjang);
		update(ix_a,panjang);
	}
	cout<<ans<<"\n";
}
