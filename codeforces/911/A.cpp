#include <bits/stdc++.h>
using namespace std;

int main()
{
	int mn=2*1000000000;
	int n;
	cin>>n;
	int tab[100010];
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	mn=min(mn,tab[i]);
	 }
	int prev=-1;
	int ans=1e9;
	for (int i=1;i<=n;i++)
	{
		if (tab[i]==mn)
		{
			if (prev==-1)
			 prev=i;
			else
			{
				int diff=i-prev;
				ans=min(ans,diff);
				prev=i;
			}
		}
	}
	cout<<ans<<"\n";
}
