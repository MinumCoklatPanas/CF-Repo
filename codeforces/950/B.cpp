#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	vector<int> a;
	vector<int> b;
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		a.push_back(k);
	}
	for (int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		b.push_back(k);
	}
	vector<int> pref_a;
	pref_a.push_back(a[0]);
	for (int i=1;i<n;i++)
	 pref_a.push_back(a[i]+pref_a[i-1]);
	vector<int> pref_b;
	pref_b.push_back(b[0]);
	for (int i=1;i<m;i++)
	 pref_b.push_back(b[i]+pref_b[i-1]);
	int now=0;
	int ans=0;
	int tambah=0;
	for (int i=0;i<n;i++)
	{
		now+=a[i];
//		cout<<i<<" "<<now<<"\n";
		int pos=lower_bound(pref_b.begin(),pref_b.end(),now+tambah)-pref_b.begin();
		if (pref_b[pos]==now+tambah)
		{
//			cout<<now<<" now\n";
			tambah+=now;
			now=0;
			++ans;
		}
	}
	cout<<ans<<"\n";
}
