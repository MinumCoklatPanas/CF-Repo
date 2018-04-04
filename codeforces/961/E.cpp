#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> tree[800010];
ll tab[200010];

void build(int node,int l,int r)
{
	if (l==r)
	{
		tree[node].push_back(tab[l]);
		return;
	}
	int mid=(l + r)>>1;
	int child=node<<1;
	build(child,l,mid);
	build(child|1,mid+1,r);
	merge(tree[child].begin(),tree[child].end(),tree[child|1].begin(),tree[child|1].end(),back_inserter(tree[node]));
}

ll query(int node,int nodeL,int nodeR,int queryL,int queryR,ll x)
{
	if (queryL>nodeR || queryR<nodeL) return 0;
	if (queryL<=nodeL && nodeR<=queryR)
	{
		ll pos=lower_bound(tree[node].begin(),tree[node].end(),x)-tree[node].begin();
//		cout<<nodeL<<" "<<nodeR<<" "<<pos<<"\n";
//		cout<<tree[node].size()-pos<<" kurang\n";
		return (tree[node].size()-pos);
	}
	int mid=(nodeL + nodeR)>>1;
	int child=node<<1;
	return query(child,nodeL,mid,queryL,queryR,x)+query(child|1,mid+1,nodeR,queryL,queryR,x);
}

int main()
{
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	build(1,1,n);
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		
		if (tab[i]>i)
		{
			ans+=query(1,1,n,i+1,tab[i],i);
//			cout<<i<<" "<<ans<<" ians\n";
		}
		
	}
	cout<<ans<<"\n";
}
