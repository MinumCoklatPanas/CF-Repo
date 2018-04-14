#include <bits/stdc++.h>
using namespace std;

int deg[1010];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	 ans+=(deg[i]==1);
	cout<<ans<<"\n";
}
