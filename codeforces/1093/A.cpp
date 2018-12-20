#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int a;
		cin>>a;
		int ans=(a/7)+(a%7!=0);
		cout<<ans<<"\n";
	}
}