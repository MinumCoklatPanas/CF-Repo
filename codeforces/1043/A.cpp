#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int mx=0;
	int n;
	cin>>n;
	int tot=0;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		tot+=a;
		mx=max(mx,a);
	}
	while (1)
	{
		if (mx*n>2*tot)
		{
			cout<<mx<<"\n";
			return 0;
		}
		++mx;
	}
}