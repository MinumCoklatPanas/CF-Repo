#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,a,b;
	cin>>n>>a>>b;
	int tab[25];
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	int l=1;
	int r=n;
	int ans=0;
	while (l<r)
	{
		if ((tab[l]!=tab[r]) && (tab[l]!=2) && (tab[r]!=2))
		{
			cout<<"-1\n";
			return 0;
		}
		if ((tab[l]==2) && (tab[r]==2))
		 ans+=2*min(a,b);
		else
		 if (tab[l]==2)
		 {
		 	if (tab[r]==0)
		 	 ans+=a;
		 	else
		 	 ans+=b;
		 }
		 else
		if (tab[r]==2)
		{
			if (tab[l]==0)
			 ans+=a;
			else
			 ans+=b;
		}
		++l;
		--r;
	}
	if ((l==r) && (tab[l]==2))
	 ans+=min(a,b);
	cout<<ans<<"\n";
}