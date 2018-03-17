#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll BIT[500010];
vector<ll> compress;
map<ll,ll> ix;
ll tab[500010];
ll prefsum[500010];
ll n;
int len;

void update(int x,ll val)
{
	for( ; x<=len;x+=(x&-x))
	 BIT[x]+=val;
}

ll query(int x)
{
	ll res=0;
	for ( ; x; x-=(x&-x))
	 res+=BIT[x];
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
	 cin>>tab[i];
	ll sum=0;
	for (int i=1;i<=n;i++)
	{
		sum+=tab[i];
		prefsum[i]=sum;
		compress.push_back(sum);
	}
	sort(compress.begin(),compress.end());
	compress.erase(unique(compress.begin(),compress.end()),compress.end());
	len=compress.size();
	for (int i=0;i<len;i++)
	 ix[compress[i]]=i+1;
	ll ans=0;
	for (int i=1;i<n;i++)
	{
		ll kanan=prefsum[n]-prefsum[i];
		ll kiri=prefsum[i];
//		cout<<kiri<<" "<<kanan<<"\n";
		if (kiri==2*kanan)
		{
//			cout<<"yo\n";
			if (!ix.count(kanan)) continue;
			ans+=query(ix[kanan])-query(ix[kanan]-1);
		}
		update(ix[kiri],1);
	}
	cout<<ans<<"\n";
	
}
