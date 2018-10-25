#include <bits/stdc++.h>
using namespace std;

int tab[200010];
int idx[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		 {
		 	cin>>tab[i];
		 	idx[tab[i]]=i;
		 }
	int bawah=0;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		// cout<<a<<" "<<idx[a]<<"\n";
		if (idx[a]<bawah)
			{
				cout<<0;
			}
		else
			{
				int ans=idx[a]-bawah;
				bawah=idx[a];
				cout<<ans;
			}
		if (i==n)
			 cout<<"\n";
		else
			 cout<<" ";
	}
}