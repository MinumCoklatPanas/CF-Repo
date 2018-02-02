#include <bits/stdc++.h>
using namespace std;

bool tree[800010];
bool tab[800010];
int tab2[200010];

void build(int node,int l,int r)
{
	if (l==r)
	{
		tree[node]=tab[l];
		return;
	}
	int child=node<<1;
	int mid=(l + r) >> 1;
	build(child,l,mid);
	build(child+1,mid+1,r);
	tree[node]=tree[child]&tree[child+1];
	return;
}

bool query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
//	cout<<nodeL<<" "<<nodeR<<"\n";
//	cout<<nodeL<<" "<<nodeR<<" "<<queryL<<" "<<queryR<<"\n";
//	return false;
	if (queryR<nodeL || queryL>nodeR) return true;
	if (queryL<=nodeL && nodeR<=queryR) return tree[node];
	int child=node<<1;
	int mid=(nodeL + nodeR)>>1;
	bool kiri=query(child,nodeL,mid,queryL,queryR);
	bool kanan=query(child+1,mid+1,nodeR,queryL,queryR);
	return kiri&kanan;
}
int n;
bool sorted()
{
	for (int i=0;i<n-1;i++)
	 if (tab[i]>tab[i+1]) return false;
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0;i<n;i++)
	 {
	 	cin>>tab2[i];
	 	--tab2[i];
	 }
	string s;
	cin>>s;
	for (int i=0;i<s.length();i++)
	{
		tab[i]=(s[i]=='1');
	}
	build(1,0,s.length()-1);
//	return 0;
	for (int i=0;i<n;i++)
	{
		if (tab2[i]==i) continue;
//		cout<<i<<" "<<tab2[i]<<" i tab\n";
		if (tab2[i]>i)
		{
			if (!query(1,0,s.length()-1,i,tab2[i]-1))
			{
				cout<<"NO\n";
				return 0;
			}
		}
		else
		 {
		 	if (!query(1,0,s.length()-1,tab2[i],i-1))
		 	{
		 		cout<<"NO\n";
		 		return 0;
			}
		 }
	}
	cout<<"YES\n";
}
