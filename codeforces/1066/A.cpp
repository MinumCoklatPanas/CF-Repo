#include <bits/stdc++.h>
using namespace std;

int cei(int a,int b)
{
	return ((a/b)+(a%b!=0));
}

int cnt(int l,int r,int v)
{
	if (l>r) return 0;
	return (r/v)-cei(l,v)+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int L,v,l,r;
		cin>>L>>v>>l>>r;
		int kiri=cnt(1,l-1,v);
		int kanan=cnt(r+1,L,v);
		int ans=kiri+kanan;
		cout<<ans<<"\n";
	}
}