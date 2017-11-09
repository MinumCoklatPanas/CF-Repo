#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int tab[1010];
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	int ans=0;
	for (int i=2;i<n;i++)
	{
		if (tab[i-1]>tab[i] && tab[i]<tab[i+1]) ++ans;
		else if (tab[i-1]<tab[i] && tab[i]>tab[i+1]) ++ans;
	}
	cout<<ans<<"\n";
}
