#include <bits/stdc++.h>
using namespace std;

struct laz{
	int ki=0;
	int ka=0;
	int leaf;
};

pair<int,int> tree[400010];
laz lazy[400010];
int a[100010];
int b[100010];

void build(int node,int l,int r)
{
	if (l==r)
	{
		lazy[node].leaf=1;
		return;
	}
	int child=node<<1;
	int mid=(l + r)>>1;
	build(child,l,mid);
	build(child|1,mid+1,r);
	lazy[node].leaf=lazy[child].leaf+lazy[child|1].leaf;
	return;
}

void upd(int node,int l,int r)
{
	lazy[node].ki=l;
	lazy[node].ka=r;
	tree[node].first=l;
	tree[node].second=r;
	return;
}

void propagate(int node,int l,int r)
{
	if (lazy[node].ki==0 || lazy[node].ka==0) return;
	int child=node<<1;
	int banyak=r-l+1;
	int mid=(banyak)>>1;
//	cout<<lazy[node].ki<<" "<<lazy[node].ka<<" "<<lazy[node].leaf<<" node kika leaf\n";
//	cout<<lazy[node].ki<<" "<<lazy[child].leaf+lazy[node].ki-1<<" updatekiri\n";
//	cout<<lazy[node].ki+lazy[child].leaf<<" "
	upd(child,lazy[node].ki,lazy[child].leaf+lazy[node].ki-1);
	upd(child|1,lazy[node].ki+lazy[child].leaf,lazy[node].ki+lazy[node].leaf-1);
	lazy[node].ki=lazy[node].ka=0;
	return;
	
}

void range_update(int node,int nodeL,int nodeR,int queryL,int queryR,int l,int r)
{
	if (queryL>nodeR || queryR<nodeL) return;
	if (queryL<=nodeL && nodeR<=queryR)
	{
		int banyak=nodeR-nodeL+1;
		int kiri=nodeL-queryL+1;
		int kanan=kiri+banyak-1;
//		cout<<nodeL<<" "<<nodeR<<" node\n";
//		cout<<kiri<<" "<<kanan<<" kika\n";
//		cout<<l<<" "<<r<<" lr\n";
//		cout<<kiri+l-1<<" "<<kanan+l-1<<" banyak\n";
//		cout<<"UPDATE\n";
		upd(node,kiri+l-1,kanan+l-1);
		return;
	}
	propagate(node,nodeL,nodeR);
	int child=node<<1;
	int mid=(nodeL + nodeR)>>1;
	range_update(child,nodeL,mid,queryL,queryR,l,r);
	range_update(child|1,mid+1,nodeR,queryL,queryR,l,r);
	return;
}

int get(int node,int l,int r,int ix)
{
//	cout<<l<<" "<<r<<" lr\n";
//	cout<<tree[node].first<<" "<<tree[node].second<<" kika\n";
	if (l==r) return tree[node].first;
	propagate(node,l,r);
	int child=node<<1;
	int mid=(l + r)>>1;
	return (ix>mid ? get(child|1,mid+1,r,ix) : get(child,l,mid,ix));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 cin>>a[i];
	for (int i=1;i<=n;i++)
	 cin>>b[i];
	build(1,1,n);
	while(m--)
	{
		int ask;
		cin>>ask;
		if (ask==2)
		{
//			cout<<"DUA\n";
			int k;
			cin>>k;
//			cout<<k<<" ";
			int ix=get(1,1,n,k);
//			cout<<ix<<" ix\n";
			cout<<(ix ? a[ix] : b[k])<<"\n";
//			cout<<"END\n";
		}
		else
		 {
//		 	cout<<"SATU\n";
		 	int x,y,k;
		 	cin>>x>>y>>k;
		 	range_update(1,1,n,y,y+k-1,x,x+k-1);
//		 	cout<<"END\n";
		 }
	}
}
