#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans=0;
	while (n>0)
	{
		ans+=n%2;
		n/=2;
	}
	cout<<ans<<"\n";
}