#include <bits/stdc++.h>
using namespace std;

#define INF 1e18
typedef long long ll;
ll tree[800010];
ll lazy[900010];
ll tab[200010];

void upd(ll node,ll l,ll r,ll x)
{
	lazy[node]+=x;
	tree[node]+=x;
	return;
}

void propagate(ll node,ll l,ll r)
{
	ll mid=(l + r) >> 1;
	upd(node*2,l,mid,lazy[node]);
	upd(node*2+1,mid+1,r,lazy[node]);
	lazy[node]=0;
	return;
}

void build(ll node,ll l,ll r)
{
	if (l==r)
	{
		tree[node]=tab[l];
		return;
	}
	ll mid=(l + r) >> 1;
	ll idxL=node*2,idxR=node*2+1;
	build(idxL,l,mid);
	build(idxR,mid+1,r);
	tree[node]=min(tree[idxL],tree[idxR]);
	return;
}

void inc(ll node,ll nodeL,ll nodeR,ll x,ll queryL,ll queryR)
{
	if (queryR<nodeL || queryL>nodeR) return;
	if (queryL<=nodeL && nodeR<=queryR)
	{
		upd(node,nodeL,nodeR,x);
		return;
	}
	propagate(node,nodeL,nodeR);
	ll mid=(nodeL + nodeR) >> 1;
	ll idxL=node*2,idxR=node*2+1;
	inc(idxL,nodeL,mid,x,queryL,queryR);
	inc(idxR,mid+1,nodeR,x,queryL,queryR);
	tree[node]=min(tree[idxL],tree[idxR]);
}

ll query(ll node,ll nodeL,ll nodeR,ll queryL,ll queryR)
{
	if (queryR<nodeL || queryL>nodeR) return -INF;
//	cout<<nodeL<<" "<<nodeR<<" node\n";
//	cout<<tree[node]<<" tree\n";
	if (queryL<=nodeL && nodeR<=queryR) {
//		cout<<1<<"\n";
		return tree[node];
	}
	propagate(node,nodeL,nodeR);
	ll mid=(nodeL + nodeR) >> 1;
	ll idxL=node*2,idxR=node*2+1;
	ll kiri=query(idxL,nodeL,mid,queryL,queryR);
	ll kanan=query(idxR,mid+1,nodeR,queryL,queryR);
	if (kiri==-INF) return kanan;
	if (kanan==-INF) return kiri;
	return min(kiri,kanan);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
	ll n;
	cin>>n;
	for (ll i=0;i<n;i++)
	 cin>>tab[i];
	build(1,0,n-1);
//	return 0;
	ll q;
	cin>>q;
//	return 0;
	string s;
	getline(cin,s);
	for (ll i=1;i<=q;i++)
	{
//		string s;
		getline(cin,s);
//		cout<<s<<"\n";
		ll spasi=0;
		for (ll j=0;j<s.length();j++)
		 if (s[j]==' ') ++spasi;
		if (spasi==1)
		{
//			cout<<"yo\n";
			string tmp;
			tmp="";
			ll j=0;
			while (s[j]!=' ')
			 {
			 	tmp+=s[j];
			 	++j;
			 }
			++j;
			ll a;
			istringstream(tmp) >> a;
			tmp="";
			while (j!=s.length())
			{
				tmp+=s[j];
				++j;
			}
			ll b;
			istringstream(tmp) >> b;
//			cout<<a<<" "<<b<<"\n";
			if (a<=b)
			 cout<<query(1,0,n-1,a,b)<<"\n";
			else
			 {
//			 	cout<<"KIRI\n";
			 	ll kiri=query(1,0,n-1,a,n-1);
//			 	cout<<"KANAN\n";
			 	ll kanan=query(1,0,n-1,0,b);
//			 	cout<<kiri<<" "<<kanan<<"\n";
			 	cout<<min(kiri,kanan)<<"\n";
			 } 
		}
		else
		 {
		 	string tmp;
		 	tmp="";
		 	ll j=0;
		 	while (s[j]!=' ')
		 	{
		 		tmp+=s[j];
		 		++j;
			}
			++j;
			ll a;
			istringstream(tmp) >> a;
			tmp="";
			while (s[j]!=' ')
			{
				tmp+=s[j];
				++j;
			}
			++j;
			ll b;
			istringstream(tmp) >> b;
			tmp="";
			while (j!=s.length())
			{
				tmp+=s[j];
				++j;
			}
			ll v;
			istringstream(tmp) >> v;
			if (a<=b)
			 inc(1,0,n-1,v,a,b);
			else
			{
				inc(1,0,n-1,v,a,n-1);
				inc(1,0,n-1,v,0,b);
			}
		 }
		
	}
}
