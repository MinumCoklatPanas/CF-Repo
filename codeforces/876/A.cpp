#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	if (n==1)
	{
		cout<<0<<"\n";
		return 0;
	}
	int ans=min(a,b);
	int mn=min(min(a,b),c);
	ans+=mn*(n-2);
	cout<<ans<<"\n";
}
