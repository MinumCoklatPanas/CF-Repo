#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	int mn=min(min(a,b),c);
	int mx=max(max(a,b),c);
	int md=a+b+c-(mn+mx);
	int ans=0;
	while (mn+md<=mx)
	{
		++ans;
		++md;
	}
	cout<<ans<<"\n";
}