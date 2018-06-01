#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map< ll, vector< pair<ll,ll> > > bisa;
vector< pair<ll,ll> > nums[200010];
ll sum[200010];
set<ll> mungkin;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	for (ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for (ll j=1;j<=k;j++)
		{
			ll a;
			cin>>a;
			nums[i].push_back(make_pair(a,j));
			sum[i]+=a;
		}
	}
	for (ll i=1;i<=n;i++)
	 sort(nums[i].begin(),nums[i].end());
	for (ll i=1;i<=n;i++)
	{
		ll j=0;
		ll now=nums[i][j].first;
		while (j<nums[i].size())
		{
			mungkin.insert(sum[i]-now);
			bisa[sum[i]-now].push_back(make_pair(i,nums[i][j].second));
			while (nums[i][j].first==now && j<nums[i].size())
			 ++j;
			now=nums[i][j].first;
		}
	}
	for (set<ll>::iterator it=mungkin.begin();it!=mungkin.end();++it)
	{
		ll now=*it;
		if (bisa[now].size()>1)
		{
			cout<<"YES\n";
			cout<<bisa[now][0].first<<" "<<bisa[now][0].second<<"\n";
			int i=1;
			while (bisa[now][i].first==bisa[now][0].first)
			 ++i;
			cout<<bisa[now][i].first<<" "<<bisa[now][i].second<<"\n";
			return 0;
		}
	}
	cout<<"NO\n";
}
