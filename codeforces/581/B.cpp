#include <bits/stdc++.h>
using namespace std;

int tab[100010];
int mx[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>tab[i];
	for (int i=n;i>=1;i--)
	{
		mx[i]=max(tab[i],mx[i+1]);
	}
	for (int i=1;i<=n;i++)
	{
		int right=mx[i+1];
		if (tab[i]>right)
			cout<<0;
		else
			cout<<right-tab[i]+1;
		if (i==n)
			cout<<"\n";
		else
			cout<<" ";
	}
}