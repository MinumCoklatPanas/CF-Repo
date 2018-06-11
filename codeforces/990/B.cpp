#include <bits/stdc++.h>
using namespace std;

int kurang[1000010];
int frek[1000010];

int main()
{
	int n,k;
	cin>>n>>k;
	int mx=0;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		frek[a]++;
		mx=max(mx,a);
	}
	int ans=n;
	for (int i=mx;i>=1;i--)
	{
		if (!frek[i]) continue;
		kurang[max(i-k,1)]++;
		kurang[i]--;
	}
	for (int i=1;i<=mx;i++)
	 kurang[i]+=kurang[i-1];
	for (int i=1;i<=mx;i++)
	{
		if (!frek[i] || !kurang[i]) continue;
		ans-=frek[i];
	}
	cout<<ans<<"\n";
}
