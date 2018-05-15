#include <bits/stdc++.h>
using namespace std;

int frek[2][6];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		frek[0][a]++;
	}
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		frek[1][a]++;
	}
	for (int i=1;i<=5;i++)
	{
		if ((frek[0][i]+frek[1][i])%2!=0)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	int ans=0;
	for (int i=1;i<=5;i++)
	{
		if (frek[0][i]>=frek[1][i]) continue;
		while (frek[0][i]!=frek[1][i])
		{
			for (int j=1;j<=5;j++)
			{
				if (i==j) continue;
				if (frek[0][j]<=frek[1][j]) continue;
				frek[0][j]--;
				frek[1][j]++;
				frek[1][i]--;
				frek[0][i]++;
				++ans;
				break;
			}
		}
	}
	cout<<ans<<"\n";
}
