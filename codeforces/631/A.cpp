#include <bits/stdc++.h>
using namespace std;

int tree[2][4010];
int a[1010];
int b[1010];

void build(int node,int l,int r)
{
	if (l==r)
	{
		tree[0][node]=a[l];
		tree[1][node]=b[l];
		return;
	}
	int child=node<<1;
	int mid=(l + r)>>1;
	build(child,l,mid);
	build(child|1,mid+1,r);
	tree[0][node]=tree[0][child]|tree[0][child|1];
	tree[1][node]=tree[1][child]|tree[1][child|1];
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR,int id)
{
	if (queryL>nodeR || queryR<nodeL) return 0;
	if (queryL<=nodeL && nodeR<=queryR) return tree[id][node];
	int mid=(nodeL + nodeR)>>1;
	int child=node<<1;
	return query(child,nodeL,mid,queryL,queryR,id)|query(child|1,mid+1,nodeR,queryL,queryR,id);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>a[i];
	for (int i=1;i<=n;i++)
	 cin>>b[i];
	build(1,1,n);
//	return 0;
	int ans=0;
	for (int i=1;i<=n;i++)
	 for (int j=i;j<=n;j++)
	 {
	 	int now=query(1,1,n,i,j,0)+query(1,1,n,i,j,1);
	 	ans=max(ans,now);
	 }
	cout<<ans<<"\n";
}
