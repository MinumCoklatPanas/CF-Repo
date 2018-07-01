#include <bits/stdc++.h>
using namespace std;

int tab[110];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	int ans=0;
	for (int i=1;i<n;i++)
	 for (int j=1;j<=n;j++)
	  ans=max(ans,abs(tab[i]-tab[j]));
	cout<<ans<<"\n";
}