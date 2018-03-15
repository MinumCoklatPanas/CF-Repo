#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const
 ll MAXN=2e5;

ll tab[MAXN+10];
pair<ll,ll> ranking[MAXN+10];
pair<int,int> ask[MAXN+10];
priority_queue<ll> pq;
ll tree[4*MAXN+10];
ll lazy[4*MAXN+10];
ll BIT[MAXN+10];
int n,q;

void upd(int node,int l,int r,ll val)
{
	lazy[node]+=val;
	tree[node]+=(r-l+1)*val*1ll;
	return;
}

void propagate(int node,int l,int r)
{
	int mid=(l + r)>>1;
	int child=node<<1;
	upd(child,l,mid,lazy[node]);
	upd(child|1,mid+1,r,lazy[node]);
	lazy[node]=0;
}

void range_update(int node,int nodeL,int nodeR,int queryL,int queryR)
{
	if (queryL>nodeR || queryR<nodeL) return;
	if (queryL<=nodeL && nodeR<=queryR)
	{
		upd(node,nodeL,nodeR,1);
		return;
	}
	propagate(node,nodeL,nodeR);
	int child=node<<1;
	int mid=(nodeL + nodeR)>>1;
	range_update(child,nodeL,mid,queryL,queryR);
	range_update(child|1,mid+1,nodeR,queryL,queryR);
	tree[node]=tree[child]+tree[child|1];
}

ll get(int node,int nodeL,int nodeR,int ix)
{
	if (nodeL==nodeR) return tree[node];
	propagate(node,nodeL,nodeR);
	int child=node<<1;
	int mid=(nodeL + nodeR)>>1;
	return (ix>mid ? get(child|1,mid+1,nodeR,ix) : get(child,nodeL,mid,ix));
}

void update(int x,ll val)
{
	for ( ; x<=n; x+=(x & -x))
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
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		pq.push(-k);
	}
	for (int i=1;i<=q;i++)
	{
		cin>>ask[i].first>>ask[i].second;
		range_update(1,1,n,ask[i].first,ask[i].second);
	}
	for (int i=1;i<=n;i++)
	{
		ranking[i].first=get(1,1,n,i);
		ranking[i].second=i;
	}
	sort(ranking+1,ranking+n+1);
	for (int i=1;i<=n;i++)
	{
		tab[ranking[i].second]=-pq.top();
		pq.pop();
	}
//	for (int i=1;i<=n;i++)
//	 cout<<tab[i]<<" ";
//	cout<<"\n";
	for (int i=1;i<=n;i++)
	{
		update(i,tab[i]);
	}
	ll ans=0;
	for (int i=1;i<=q;i++)
	{
		ans+=query(ask[i].second)-query(ask[i].first-1);
	}
	cout<<ans<<"\n";
}
