#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int tab[100010];
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	sort(tab+1,tab+n+1);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int tim;
		if (tab[i]>500000)
		 tim=1000000-tab[i];
		else
		 tim=tab[i]-1;
		ans=max(ans,tim);
	}
	cout<<ans<<"\n";
}
