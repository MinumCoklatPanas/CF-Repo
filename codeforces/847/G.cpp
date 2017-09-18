#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n,frek[10];
	memset(frek,0,sizeof(frek));
	string s;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>s;
		for (j=0;j<7;j++)
		{
			if (s[j]=='1')
			 frek[j+1]++;
		}
	}
	int ans=0;
	for (i=1;i<=7;i++)
	 ans=max(ans,frek[i]);
	cout<<ans<<"\n";
}