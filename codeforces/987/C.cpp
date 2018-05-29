#include <bits/stdc++.h>
using namespace std;

int s[3010];
int c[3010];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>s[i];
	for (int i=1;i<=n;i++)
	 cin>>c[i];
	int ans=-1;
	for (int i=2;i<n;i++)
	{
		int kurang=1e9;
		for (int j=1;j<i;j++)
		{
			if (s[j]<s[i])
			 kurang=min(kurang,c[j]);
		}
		if (kurang==1e9) continue;
		int lebih=1e9;
		for (int j=i+1;j<=n;j++)
		{
			if (s[j]>s[i])
			 lebih=min(lebih,c[j]);
		}
		if (lebih==1e9) continue;
		if (ans==-1)
		 ans=kurang+lebih+c[i];
		else
		 ans=min(ans,kurang+lebih+c[i]);
	}
	cout<<ans<<"\n";
}
