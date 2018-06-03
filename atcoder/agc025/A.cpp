#include <bits/stdc++.h>
using namespace std;

int sum(int x)
{
	int ans=0;
	while (x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int ans=1e9;
	for (int i=1;i<n;i++)
	{
		int a=i;
		int b=n-i;
		int tot=sum(a)+sum(b);
		ans=min(ans,tot);
	}
	cout<<ans<<"\n";
}