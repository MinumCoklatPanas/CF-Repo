#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		ll a;
		cin>>a;
		ll pc=__builtin_popcountll(a);
		ll ans=(1ll<<pc);
		cout<<ans<<"\n";
	}
}