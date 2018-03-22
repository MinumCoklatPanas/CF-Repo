#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll BIT[2][1000010];
vector<ll> compress;
map<ll,ll> mp;
ll tab[1000010];
ll len;

void update(ll x,ll val,ll id)
{
	for ( ; x<=len; x+=(x&-x))
	 BIT[id][x]+=val;
}

ll query(ll x,ll id)
{
	ll res=0;
	for ( ; x; x-=(x&-x))
	 res+=BIT[id][x];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>tab[i];
		compress.push_back(tab[i]);
	}
	sort(compress.begin(),compress.end());
	len=(ll)compress.size();
	for (int i=0;i<len;i++)
	 mp[compress[i]]=i+1;
	for (int i=0;i<len;i++)
	 update(mp[compress[i]],1,0);
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
//		cout<<i<<" i\n";
		ll ix=mp[tab[i]];
//		cout<<ix<<" ix\n";
		update(ix,1,1);
		ll ans1=query(len,1)-query(ix,1);
		ll ans2=query(ix-1,0);
		ans+=ans1*ans2;
//		cout<<ans1<<" "<<ans2<<"\n";
		update(ix,-1,0);
	}
	cout<<ans<<"\n";
}
