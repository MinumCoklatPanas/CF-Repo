#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	if (n<=2)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	cout<<(n/2)<<" ";
	for (int i=2;i<=n;i+=2)
	 cout<<i<<" ";
	cout<<"\n";
	cout<<((n+1)/2)<<" ";
	for (int i=1;i<=n;i+=2)
	 cout<<i<<" ";
	cout<<"\n";
}